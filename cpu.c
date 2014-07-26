/*
 * Author   : Li Xiao
 * Date     : Jan 7, 2013
 * Function : Calculate cpu occupation
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// cpu info
struct occupy {
	char name[20];
	unsigned int user;
	unsigned int nice;
	unsigned int system;
	unsigned int idle;
};

float g_cpu_used;
int cpu_num;

// read cpu info from /proc/stat
void get_occupy(struct occupy *p)
{
	FILE *fp;
	int i;
	char buff[1024];
	
	if ((fp = fopen("/proc/stat", "r")) == NULL) {
		fprintf(stderr, "cant open /proc/stat\n");
		fclose(fp);
	}
	fgets(buff, sizeof(buff), fp);
	for (i=0; i<cpu_num; i++) {
		fgets(buff, sizeof(buff), fp);
		sscanf(buff, "%s%u%u%u%u", p[i].name, &(p[i].user), &(p[i].nice), &(p[i].system), &(p[i].idle));
	}
	fclose(fp);
}

// calculate cpu occupation
void cal_occupy(struct occupy *p1, struct occupy *p2)
{
	double od, nd;
	od = (double)(p1->user + p1->nice + p1->system + p1->idle);
	nd = (double)(p2->user + p2->nice + p2->system + p2->idle);
	g_cpu_used = ((p2->user + p2->system + p2->nice) - (p1->user + p1->system + p1->nice)) / (nd - od) * 100;
}

int main(int argc, char **argv)
{
	struct occupy ocpu[10];
	struct occupy ncpu[10];
	int i;
	
	pid_t pid = fork();
	if (pid == 0)
		execvp(argv[1], &argv[1]);	//start another process to observe cpu
	else {
		cpu_num = sysconf(_SC_NPROCESSORS_ONLN);
		while (1) {
			get_occupy(ocpu);
			sleep(1);
			get_occupy(ncpu);
			system("clear");
			for (i=0; i<cpu_num; i++) {
				cal_occupy(&ocpu[i], &ncpu[i]);
				printf("%s %.4f%% \n",ocpu[i].name, g_cpu_used);
			}
			sleep(1);
		}
	}
	
	return 0;
}

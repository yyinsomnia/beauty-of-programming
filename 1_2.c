#include <time.h>
#include <unistd.h>

int main()
{
	const int busy_time = 5;		// 10ms
	const int idle_time = busy_time;//same ration will lead to 50% cpu usage

	int start_time = 0;
	while (1) {
		start_time = clock();
		while ((clock() - start_time)*1000/CLOCKS_PER_SEC <= busy_time)
			;
		usleep(1000 * idle_time);
	}

	return 0;
}
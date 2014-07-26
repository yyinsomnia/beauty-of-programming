/**
 *	my mac cpu: 2.4 GHz Intel Core i5
 */
 #include <unistd.h>
int main()
{
	int i;
	for ( ; ;) {
		for (i = 0; i < 4800000; i++) //why 480 not 960?
			;
		usleep(10000);
	}
	return 0;
}
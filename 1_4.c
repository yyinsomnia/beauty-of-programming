#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

const int SAMPLING_COUNT = 200;
const double PI = 3.1415926535;
const int TOTAL_AMPLITUDE = 300;

int main()
{
	int i , j;
	int busy_span[SAMPLING_COUNT];
	int amplitude = TOTAL_AMPLITUDE / 2;
	double radian = 0.0;
	double redian_increment = (2.0 * PI ) /  SAMPLING_COUNT;
	for (i = 0; i < SAMPLING_COUNT; i++) {
		busy_span[i] = amplitude + sin(radian) * amplitude;
		radian += redian_increment;
	}

	int start_time = 0;
	for (j = 0; ; j=(j+1) % SAMPLING_COUNT) {
		start_time = clock();
		while ((clock() - start_time) * 1000 / CLOCKS_PER_SEC <= busy_span[j])
			;
		usleep(1000 * (TOTAL_AMPLITUDE - busy_span[j]));
	}
	return 0;
}
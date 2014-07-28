#include <stdio.h>

int main()
{
	int i;
	for (i = 81; i >= 1; i--) {
		if (((i + 9 - 1) / 9) % 3 == ((i % 9) ? (i % 9) : 9) % 3) //1-9
			printf("A = %d, B = %d\n", (i + 9 - 1) / 9, ((i % 9) ? (i % 9) : 9));
	}
	i ＝ 81；
	while(i--) {
		if (i / 9 % 3 == i % 9 % 3) //0-8
			;
		printf("A = %d, B = %d\n", i / 9 + 1, i % 9 + 1);
	}
	return 0;
}
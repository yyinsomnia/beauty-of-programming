#include <stdio.h>

int main()
{
	int i;
	for (i = 81; i >= 1; i--) {
		if (((i + 9 - 1) / 9) % 3 == ((i % 9) ? (i % 9) : 9) % 3)
			printf("A = %d, B = %d\n", (i + 9 - 1) / 9, ((i % 9) ? (i % 9) : 9));
	}
	return 0;
}
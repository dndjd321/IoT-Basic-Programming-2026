// Chapter05_05_app/main.c
// 구구단

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i, j = 0;

	for (i = 2; i <= 9; i++) {
		printf("============================================================================================================================================\n");
		printf("%d단 시작\n", i);

		for (j = 1; j <= 9; j++) {
			printf("%d × %d = %2d\t", i, j, i * j);
		}
		printf("\n");
	}

	return 0;
}
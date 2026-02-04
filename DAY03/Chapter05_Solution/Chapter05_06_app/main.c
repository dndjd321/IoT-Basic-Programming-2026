// Chapter05_06_app/main.c
// break, continue

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i, sum = 0;

	for (i = 1; i <= 10; i++) 
	{
		sum += i;
		if (sum > 30) {
			break;
		}
	}

	printf("누적 합은 %d 입니다.\n", sum);
	printf("마지막으로 더한 값 %d 입니다.\n", i);

	return 0;
}
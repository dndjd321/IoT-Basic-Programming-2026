// Chapter01_quiz_01/quiz01.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int res;
	res = sizeof(short) > sizeof(long) ? 1 : 0;

	if (res)
		printf("short\n");
	else
		printf("long\n");

	return 0;
}
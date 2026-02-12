// Chapter19_02_app/sub.c
// 분할 컴파일 - sub.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void inputData(int* px, int* py) {
	printf("두 정수 입력 : ");
	scanf("%d %d", px, py);
}

double average(int x, int y) {
	int total;
	double avg;
	total = x + y;
	avg = total / 2.0;

	return avg;
}
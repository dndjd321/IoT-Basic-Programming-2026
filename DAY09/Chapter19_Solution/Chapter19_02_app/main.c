// Chapter19_02_app/main.c
// 분할 컴파일 - main.c

#include <stdio.h>

void inputData(int*, int*);
double average(int, int);

int main() {
	int a, b;
	double avg;

	inputData(&a, &b);
	avg = average(a, b);

	printf("%d와 %d의 평균 : %.1lf\n", a, b, avg);

	return 0;
}


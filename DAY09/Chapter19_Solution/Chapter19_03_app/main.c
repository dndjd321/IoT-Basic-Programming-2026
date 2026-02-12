// Chapter19_03_app/main.c
// main 소스코드


#include <stdio.h>

int inputData();
double average();
void printData(double);

int count = 0;
static int total = 0;

int main() {
	double avg;

	total = inputData();	// main.c에 없음
	avg = average();		// main.c에 없음
	printData(avg);			// main.c에 있음

	return 0;
}

void printData(double avg) {
	printf("입력한 양수 개수 : %d\n", count);
	printf("전체 합과 평균 : %d, %.2lf\n", total, avg);
}


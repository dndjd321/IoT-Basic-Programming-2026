// Chapter09_07_app/main.c
// 포인터 사용 이유

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* pa, int* pb);

int main() {

	int a = 10, b = 20;

	printf("원본 a, b = %d, %d\n", a, b);

	swap(&a, &b);

	printf("변경 후 a, b = %d, %d\n", a, b);

	return 0;
}

void swap(int* pa, int* pb) {

	int temp = 0;		// 교환을 위한 임시 변수
	
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
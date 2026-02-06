// Chapter09_04_app/main.c
// 포인터
// & (Ampersand 또는 and) , * ( Asterik 또는 star )

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	// 일반 변수
	int a = 10, b = 15, total;
	double avg;

	// 포인터 변수
	int* pa, * pb;
	int* pt = &total;	// 선언과 동시에 초기화
	double* pg = &avg;	// 선언과 동시에 초기화

	// *pa = *&a = a
	pa = &a;
	pb = &b;

	// 원래는 total = a + b; avg = total / 2.0;
	// 대신 포인터 변수로 위의 작업을 대체
	// *pa : a 변수의 주소가 가지고 있는 값
	// pa : a 변수의 주소 값

	*pt = *pa + *pb; // a+b;
	*pg = *pt / 2.0;

	// 결과 출력
	printf("a = %d, b = %d, total = %d, avg = %.2f\n", a, b, total, avg);

	printf("*pa = %d, *pb = %d, *pt = %d, *pg = %.2f\n", *pa, *pb, *pt, *pg);

	return 0;
}
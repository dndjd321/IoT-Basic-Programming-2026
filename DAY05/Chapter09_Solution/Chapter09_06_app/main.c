// Chapter09_06_app/main.c

// 포인터 대입 규칙
// 포인터를 사용할 때 주의할 점
// 포인터는 가리키는 변수의 형태가 같아야 함.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	int a = 10;		// 정수형 변수 선언 및 초기화
	int* p = &a;	// 정수형 포인터 변수 선언 및 초기화

	double* pd;		// 실수형 포인터 변수 선언

	//pd = p;			
	pd = &a;		// double형 포인터에 int형 변수 주소를 넣음.
	// 포인터형 변수와 일반변수의 타입을 반드시 일치시켜야 함.

	printf("%d\n", *p);
	printf("%lf\n", *pd);

	// 형변환을 사용한 포인터 대입은 가능함.
	double c = 3.14;
	int* pi;

	pd = &c;
	printf("%lf\n", *pd);

	pi = (int*)pd;			// int*로 형 변환해서 대입은 가능하다.
	printf("%lf\n", *pi);

	return 0;
}
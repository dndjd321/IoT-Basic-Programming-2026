// Chapter04_01_app/main.c
// 연산자

#define _CRT_SECURE_NO_WARNINGS	// for Visual Studio에서 안전하지 않은 함수 사용 경고 제거
#include <stdio.h>

int main() {
	// 산술 연산자
	int x, y;
	int sum, sub, mul, mod;
	double div;
	int inv;

	x = 7;
	y = 3;

	sum = x + y;			// 덧셈
	sub = x - y;			// 뺄셈
	mul = x * y;			// 곱셈
	div = (double)x / y;	// 나눗셈
	mod = x % y;			// 나머지
	inv = -x;

	printf("x = %d, y = %d:\n", x, y);
	printf("x + y = %d\n", sum);
	printf("x - y = %d\n", sub);
	printf("x × y = %d\n", mul);
	printf("x ÷ y = %.2f\n", div);
	printf("x ％ y = %d\n", mod);

	printf("inverse x = %d\n", inv);

	// 대입 연산자
	int a = 10;				// int형 변수 a에 10을 할당.
	int b = 20;

	// 증감 연산자
	++a;
	a++;
	--b;
	b--;
	
	printf("a = %d\n", a);
	printf("b = %d\n", b);





	return 0;
}
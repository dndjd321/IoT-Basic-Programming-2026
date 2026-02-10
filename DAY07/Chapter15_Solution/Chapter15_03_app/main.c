// Chapter15_03_app/main.c
// 함수 포인터
// 함수로 변수처럼 주소를 가짐. 포인터로 활용 가능
// Callback, 대리자(event) 함수 처리할 때 필요한 기능

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int Sum(int, int);
int Sub(int, int);
int Mul(int, int);
int Div(int, int);

int main() {
	int (*fp)(int, int);	// 함수 포인터 선언. 매개변수의 타입과 개수가 일치해야함.
	int res;

	fp = Sum;	// 배열의 이름만 적으면 주소. 함수의 이름만 적으면 주소.

	//res = Sum(10, 20);	// 일반적으로 함수 호출
	res = fp(10, 20);		// 함수 포인터로 함수 호출

	printf("Sum의 결과 : %d\n", res);

	fp = Sub;	// 함수 주소를 변경해서 pf가 Sub 함수를 사용하도록 함.
	res = fp(20, 10);
	printf("Sub의 결과 : %d\n", res);

	fp = Mul;
	res = fp(20, 10);
	printf("Mul의 결과 : %d\n", res);

	fp = Div;
	res = fp(20, 10);
	printf("Div의 결과 : %d\n", res);

	return 0;
}

int Sum(int x, int y) {
	return x + y;
}

int Sub(int x, int y) {
	return x - y;
}

int Mul(int x, int y) {
	return x * y;
}

int Div(int x, int y) {
	return x / y;
}
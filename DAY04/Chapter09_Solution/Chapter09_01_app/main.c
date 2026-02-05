// Chapter09_01_app/main.c
// 포인터 이전 로컬 변수, 변수 스코프

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Func();
int Add(int);

int x = 10;		// 전역 변수 

int main() {
	// 기본 변수 스코프
	int x = 30;
	printf("main x = %d\n", x);
	Func();
	printf("main x = %d\n", x);

	// 블록 스코프
	int a = 1;
	if (a == 1) {
		int b = 2;
		printf("블록 내부 : a = %d, b = %d\n", a, b);
	}

	//printf("블록 외부 : a = %d, b = %d\n", a, b);	
	//printf("b = %d", b);	// 블록내부에서 선언한 변수 b는 블록 외부에서는 사용 불가. 컴파일 에러 남.

	// 함수 스코프
	int y = 10;
	int res = Add(y);
	printf("res = %d\n", res);

	return 0;
}

void Func() {
	int x = 20;		// 지역 변수
	printf("Func x = %d\n", x);
}

int Add(int x) {
	x += 100;
	return x;
}
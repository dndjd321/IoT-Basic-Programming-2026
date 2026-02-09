// Chapter13_01_app/main.c
// 지역변수, 전역변수

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void assign();

int a;	// 전역 변수

int main() {
	auto int a = 10;	// 지역 변수
	int b = 20;

	assign();
	printf("main() > a : %d\n", a);

	printf("교환 전 a : %d, b : %d\n", a, b);
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}

	printf("교환 후 a : %d, b : %d\n", a, b);

	return 0;
}

void assign() {
	int a;

	a = 100;
	printf("assign() > a : %d\n", a);
}
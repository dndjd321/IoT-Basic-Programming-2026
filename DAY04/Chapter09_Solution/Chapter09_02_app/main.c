// Chapter09_02_app/main.c

// 변수의 주소 - 메모리 주소

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a=100;			// 4Byte
	double b=300.0;		// 8Byte
	char c=12;			// 1Byte

	// 주소 연산자
	printf("int형 변수 a의 주소 값 : %u\n", &a);	// '&' : 메모리 주소를 나타내는 연산자
	printf("double형 변수 b의 주소 값 : %u\n", &b);
	printf("char형 변수 c의 주소 값 : %u\n", &c);


	return 0;
}
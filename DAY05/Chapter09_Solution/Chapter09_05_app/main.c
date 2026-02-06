// Chapter09_05_app/main.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	// 일반 변수 선언
	char ch;
	int in;
	double db;

	// 포인터 변수 선언 및 초기화
	char* pch = &ch;
	int* pin = &in;
	double* pdb = &db;

	// 윈도우가 64비트 => 8byte == 8bit * 8 == 64bit
	// 현재 윈도우의 주소체계는 8byte

	// 주소 크기 출력
	printf("char형 변수 주소 크기 : %zu bytes\n", sizeof(&ch));
	printf("int형 변수 주소 크기 : %zu bytes\n", sizeof(&in));
	printf("double형 변수 주소 크기 : %zu bytes\n", sizeof(&db));

	// 포인터 크기 출력 -> 변수의 주소를 담아야 하므로 모두 8byte
	printf("char형 *변수의 크기 : %zu bytes\n", sizeof(pch));
	printf("int형 *변수의 크기 : %zu bytes\n", sizeof(pin));
	printf("double형 *변수의 크기 : %zu bytes\n", sizeof(pdb));

	// 포인터가 가리키는 변수의 크기 출력
	printf("char형 *가 가리키는 변수의 크기 : %zu bytes\n", sizeof(*pch));
	printf("int형 *가 가리키는 변수의 크기 : %zu bytes\n", sizeof(*pin));
	printf("double형 *가 가리키는 변수의 크기 : %zu bytes\n", sizeof(*pdb));


	return 0;
}
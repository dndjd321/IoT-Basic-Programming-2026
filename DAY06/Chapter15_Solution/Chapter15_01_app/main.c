// Chapter15_01_app/main.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 10;
	int* pi;
	int** ppi;

	pi = &a;
	ppi = &pi;

	printf("--------------------------------------------------\n");
	printf("변수\t변수\t&연산\t*연산\t**연산\n");
	printf("--------------------------------------------------\n");

	printf("a\t%d\t%u\n", a, &a);				// 변수 a의 값, 주소만 출력
	printf("pi\t%u\t%u\t%d\n", pi, &pi, *pi);	// pi(포인터변수) 
	printf("ppi\t%u\t%u\t%u\t%d\n", ppi, &ppi, *ppi, **ppi);

	return 0;
}
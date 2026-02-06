// Chapter10_02_app/main.c
// 배열과 포인터 차이

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int ary[3] = { 1,2,3 };
	int* pary = ary;

	printf("배열의 크기 : %zu \n", sizeof(ary));		// 3 * 4 =12byte
	printf("포인터의 크기 : %zu \n", sizeof(pary));		// 8byte

	for (int i = 0; i < 3; i++) {
		printf("%5d\t", *(pary + i));
	}

	return 0;
}

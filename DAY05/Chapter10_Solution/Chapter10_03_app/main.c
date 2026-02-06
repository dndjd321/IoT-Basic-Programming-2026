// Chapter10_03_app/main.c
// 배열값 출력하는 함수

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_ary(int ary[], int size);	// 40byte + 4byte
void print_ary2(int* pary, int size);	// 8byte + 4byte


int main() {
	int ary[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int ary2[5] = { 10,20,30,40 };

	printf("배열로 처리\n");
	print_ary(ary, (sizeof(ary) / sizeof(ary[0])));

	printf("포인터로 처리\n");
	print_ary2(ary, (sizeof(ary) / sizeof(ary[0])));
	print_ary2(ary2, (sizeof(ary2) / sizeof(ary2[0])));

	return 0;
}

void print_ary(int ary[], int size) {
	int i;

	for (i = 0; i < size; i++) {
		printf("%5d\t", ary[i]);
	}
	printf("\n");
}

void print_ary2(int* pary, int size) {
	int i;

	for (i = 0; i < size; i++) {
		printf("%5d\t", *(pary + i));
		//printf("%5d\t", pary[i]);		// 배열의 요소처럼 사용할 수도 있다.
	}
	printf("\n");
}
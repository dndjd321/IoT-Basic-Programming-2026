// Chapter16_01_app/main.c
// 메모리 동적 할당

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// malloc, free 같은 동적할당 함수가 포함된 헤더파일

int main () {

	// NULL - 아무것도 가리키지 않는 포인터 값
	// 안전한 초기화를 위해서
	// 포인터 처리가 없음을 나타내기 위해서
	// NULL != 0
	// NULL은 안전하지 않음
	// 실무에서 가장 많이나는 예외 NullPointerException(NullReferenceException)
	int* pi;	// 즉 pi 는 아무것도 가리키고 있지 않은 상태
	double* pd;

	// malloc : memory allocation(메모리 할당)
	// 1. 메모리 동적 할당 후 포인터와 연결
	pi = (int*)malloc(sizeof(int));			

	if (pi == NULL) {
		printf("# pi >> 메모리가 할당되지 않았습니다.\n");
		exit(1);	// 에러발생(1) return 후 프로그램 종료
	}

	// 1. 8byte 메모리 생성
	pd = (double*)malloc(sizeof(double));	

	if (pd == NULL) {
		printf("# pd >> 메모리가 할당되지 않았습니다.\n");
		exit(1);	// 에러발생(1) return 후 프로그램 종료
	}

	*pi = 10;		// 메모리 주소 어딘가에 동적으로 int 할당한 곳에 값을 10을 대입하라는 의미.
	*pd = 3.4;

	printf("정수형 : %d\n", *pi);
	printf("실수형 : %.1f\n", *pd);

	// 2. 메모리를 동적 할당한 것은 종료 직전 무조건 free()로 메모리를 해제(반환)해야함
	free(pi);		
	free(pd);

	return 0;		// 에러없이(0) 프로그램 종료
}
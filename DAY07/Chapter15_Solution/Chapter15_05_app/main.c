// Chapter15_05_app/main.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



int main() {
	int a = 10;
	double b = 3.5;

	void* vp;	// void Pointer
	int* pa;
	double* pb;

	// 추가적인 내용
	int* pi = (int*)vp;	// 대입연산에서는 형변환을 안써도 오류 X. 단, 명시적으로 형변환을 추가해 줄 것

	vp = &a;
	printf("a : %d\n", *(int*)vp);	// vp 를 int* 로 변경 후 사용 가능
	
	vp = &b;
	printf("b : %.1f\n", *(double*)vp);	// vp 를 double* 로 변경 후 사용 가능. void* 는 형변환 필수.

	pa = &b;	// double형을 int* 에 할당 가능
	printf("pa : %.1f\n", *(double*)pa);	// pa 를 double* 로 변경 후 사용 가능

	return 0;
}
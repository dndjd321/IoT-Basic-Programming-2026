// Chapter09_03_app/main.c
// 포인터, 간접 참조 연산자

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int a = 0;	// 일반 변수
	int* pa;	// 포인터 변수 : 다른 변수의 주소 값을 담음.

	pa = &a;	// a의 주소 값을 pa에 할당.

	// 포인터가 가리키는 변수에 값을 할당
	// 즉, pa가 가리키는 변수인 a에 값을 할당
	*pa = 100;	// 변수 a에 값을 대입하지는 않는다.

	printf("a의 값 : %d\n", a);
	printf("a의 주소 값 : %u\n", &a);
	printf("pa가 가리키는 변수의 값 : %u\n", *pa);
	printf("pa의 값 : %u\n", pa);	//pa가 가리키는 변수의 주소 값과 동일

	return 0;
}
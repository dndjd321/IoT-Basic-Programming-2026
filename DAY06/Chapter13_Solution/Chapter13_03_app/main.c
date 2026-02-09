// Chapter13_03_app/main.c
// 값 복사 전달 & 주소 복사
// return 값을 포인터 변수로 받는 방법

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//void addTen(int);
int addTen(int);

void plusTen(int*);

int* Sum(int, int);		// 매개변수는 일반변수, return은 포인터 변수

int main () {
	int a = 100;
	int* result;

	a = addTen(a);
	printf("a : %d\n", a);

	plusTen(&a);
	printf("a : %d\n", a);

	// 포인터변수 result는 Sum 함수 내의 선언되어 있는 정적변수 res의 주소값을 반환받음.
	result = Sum(40, 60);	
	printf("*result : %d\n", *result);

	return 0;
}

// 값 복사 후 return 없으면 값이 사라짐
//void addTen(int num) {
//	num = num + 10;
//}

int addTen(int num) {
	num = num + 10;
	return num;
}

void plusTen(int* pa) {
	*pa = *pa + 10;
}

int* Sum(int x, int y) {
	static int res;	// 정적 변수. static 을 써서 Sum함수가 끝나도 변수가 살아있도록 하겠다는 의미

	res = x + y;

	return &res;	// 정적 변수의 주소 값을 반환
}
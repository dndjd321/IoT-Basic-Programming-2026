// Chapter15_04_app/main.c
// 함수 포인터 활용

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void Func(int (*fp)(int, int));	// 함수 포인터를 매개변수로 가지는 함수
int Sum(int, int);
int Mul(int, int);
int Max(int, int);

int main() {
	int sel;	// 선택한 값 변수

	printf("01 두 정수의 합 \n");
	printf("02 두 정수의 곱 \n");
	printf("03 두 정수 중 최대값 \n");
	printf("원하는 연산을 선택 : ");
	scanf("%d", &sel);	// scanf는 변수의 주소 값을 넣어줘야함.

	switch (sel) {
		case 1:
			printf("더하기 연산\n");
			Func(Sum);
			break;
		case 2:
			printf("곱하기 연산\n");
			Func(Mul);
			break;
		case 3:
			printf("최대값 연산\n");
			Func(Max);
			break;
		default:
			break;
	}

	return 0;
}

void Func(int (*fp)(int, int)) {
	int x, y;
	int res;

	printf("두 정수 값을 입력하세요 : ");
	scanf("%d%d", &x, &y);
	res = fp(x, y);
	printf("결과 : %d\n", res);
}

int Sum(int x, int y) {
	return x + y;
}

int Mul(int x, int y) {
	return x * y;
}

int Max(int x, int y) {
	return x > y ? x : y;
}
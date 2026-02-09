// Chapter13_02_app/main.c
// 정적 변수 static

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void autoFunc();	// 일반 지역변수
void staticFunc();	// 정적 지역변수 사용

int main() {
	int i;

	printf("일반 지역변수 사용 함수 호출\n");
	for (i = 0; i < 3; i++) {
		autoFunc();
	}

	printf("정적 지역변수 사용 함수 호출\n");
	for (i = 0; i < 3; i++) {
		staticFunc();
	}

	return 0;
}

#pragma region autoFunc()
void autoFunc() {
	// auto int a : 함수가 호출될 때 마다 새로 생성되고 함수가 종료될때 메모리에 제거됨
	auto int a = 0;		// auto -> 0으로 초기화
	a++;

	printf("%d\n", a);
}
#pragma endregion

#pragma region staticFunc()
void staticFunc() {
	// static int a : main.c가 처음 시작될 때 메모리에 저장되어있다가, main.c가 종료될 때 메모리에서 제거됨
	static int a;		// static -> 0으로 자동 초기화됨. 직접 초기화해도 무관함.
	a++;
	printf("%d\n", a);
}
#pragma endregion



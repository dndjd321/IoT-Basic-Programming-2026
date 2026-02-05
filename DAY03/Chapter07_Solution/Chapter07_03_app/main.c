// Chapter07_03_app/main.c
// 재귀호출 함수

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fruit(void);	// 함수 선언
void fruit2(int);	// 종료 조건을 매개변수로 받는 재귀 호출 함수 선언


int main() {

	//fruit();
	fruit2(1);

	return 0;
}


void fruit(void) {	// 함수 정의
	static int count = 1;	// 정적 지역 변수
	printf("Banana, %d\n", count++);
	fruit();	// 재귀 호출
				// 함수가 자기 자신을 호출
}	

void fruit2(int count) {	// 종료 조건을 매개변수로 받는 재귀 호출 함수 정의
	printf("Apple\n");
	if (count == 3) {	// 종료 조건
		return;	// 함수 종료
	}
	fruit2(count + 1);
}
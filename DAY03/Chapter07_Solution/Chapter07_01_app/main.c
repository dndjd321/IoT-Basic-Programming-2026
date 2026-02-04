// Chapter07_01_app/main.c
// 함수 (Functions)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// Sum 함수 선언
// C에서만 거의 필수적으로 함수 선언을 해야 함
// C 최신 표준에서는 함수 선언을 하지 않아도 되지만
// 호환성을 위해 함수 선언을 하는 것이 좋음
int Sum(int x, int y);

// 매개변수 x, y 의 합을 int형으로 반환하는 Sum 함수 정의
Sum(int x, int y) {
	return x + y;
}

int main() {
	int a = 10, b = 20;
	int result = 0;

	// return이 있는 함수를 호출하면 반드시 Left Value(변수)가 필요
	result = Sum(a, b);  // Sum 함수 호출

	printf("result : %d\n", result);

	return 0;
}


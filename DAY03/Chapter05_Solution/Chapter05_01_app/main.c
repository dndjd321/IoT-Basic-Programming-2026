// Chapter05_01_app/main.c
// 제어문 - 선택문
// 선택에 따라 로직이 다르게 동작하도록 제어하는 문장

// if (조건) {
//	조건이 참일 때, 로직 수행; 
// } else { 
//	조건이 거짓일 때, 로직 수행; }

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	// 표준 입출력 헤더 파일

int main(void) {
	
	int a = 10, b = 0;

	// if ~ else 문
	if ( a > 10 ) {
		b = a;
	}
	else {
		b = 1000;
	}

	// if ~ else if ~ else 문
	if (a > 0) {
		b = 1;
	}
	else if (a == 0) {
		b = 2;
	}
	else {
		b = 3;
	}

	printf("a : %d, b : %d\n", a, b);

	int age = 20;	// 나이
	int gender = 1; // 1: 남자, 0: 여자

	if (age > 12) 
	{
		if (gender == 1)
			printf("남탕, 성인. 20,000원.\n");
		else
			printf("여탕, 성인. 20,000원.\n");
	}
	else
	{
		if (gender == 1)
			printf("남탕, 소인. 12,000원.\n");
		else
			printf("여탕, 소인. 12,000원.\n");
	}

	return 0;
}


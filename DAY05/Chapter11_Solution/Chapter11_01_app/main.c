// Chapter11_01_app/main.c
// 문자

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char small, cap = 'G';

	if ((cap >= 'A') && (cap <= 'Z')) {	// 65 ~ 90
		//small = cap + 32;				// 영어 대문자 -> 소문자 값
		small = cap + ('a' - 'A');		// 97 - 65 = 32 'z' - 'Z'
	}

	printf("대문자 값 : %c\n", cap);
	printf("소문자 값 : %c\n", small);


	return 0;
}
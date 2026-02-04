// Chapter05_04_app/main.c
// for

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 1;

	/*
		for (초기값; 조건식; 증감식) {
			반복 실행할 코드;
		}
	*/

	for (int i = 0; i < 3; i++) {
		a *= 2;
	}

	printf("a : %d\n", a);	// for문 탈출 후 a 값 콘솔 출력
							// 결과 => i == 3 일 때, a : 8


	// $를 10회 출력하는 for문 작성
	for (int i = 0; i < 10; i++) {
		printf("$");	// printf("%d", "$");, printf("%c", '$'); 다 같은 결과
	}

	printf("\n");	// 줄바꿈

	// 이중 for 문
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			printf("*");
		}
		printf("\n");	// 한 줄 출력 후 줄바꿈
	}

	return 0;
}
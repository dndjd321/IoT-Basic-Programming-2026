// Chapter05_03_app/main.c
// 반복문

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	/*
		while 문
		while (조건식) {
			반복 실행할 문장;
		}
	*/ 
	
	int a = 1;

	while (a < 10) {
		a *= 2;
	}

	printf("a : %d\n", a);

	a = 0;
	while (a >  0) {
		printf("while 실행\n");		// 출력 X
		a--;
	}

	printf("while문 종료\n");

	/*
		do ~ while 문 : 반복 내의 실행문이 무조건 1회는 실행됨.
		do {
			반복 실행할 문장;
		} while (조건식);
	*/

	a = 1;

	do {
		a *= 2;
	} while (a < 10);


	a = 0;
	do {
		printf("do~while문 실행\n");	// 출력 O - 1회만
		a--;
	} while (a > 0);
	printf("do~while문 종료\n");

	return 0;
}
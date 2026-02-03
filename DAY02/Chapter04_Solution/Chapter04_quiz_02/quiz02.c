// Chapter04_quiz_02/quiz02.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	
	int seats = 70;		// 좌석 수
	int audience = 65;	// 입장객 수
	double rate = 0.0;	// 입장률

	rate = (double)audience / seats * 100;	// 입장률 계산 ( 백분율로 나타내기 위해 * 100 )

	printf("입장률: %.1f%%\n", rate);

	return 0;
}
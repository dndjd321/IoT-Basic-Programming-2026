// Chapter14_quiz_app/main.c
// 14장 3번 퀴즈

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char mark[5][5] = { 0 };
	int i, j;

	// X 모양
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (i == j || i + j ==4) {
				mark[i][j] = 'X';
			}
		}
	}

	// + 모양
	/*for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (j == 2 || i == 2) {
				mark[i][j] = 'X';
			}
		}
	}*/

	// ㅁ 모양
	/*for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if ((i == 0 || i == 4) || (j == 0 || j == 4)) {
				mark[i][j] = 'X';
			}
		}
	}*/

	// 결과 출력
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (mark[i][j] != 0) {
				printf("[%c]", mark[i][j]);
			}
			else {
				printf("[ ]");
			}
		}

		printf("\n");
	}

	return 0;
}
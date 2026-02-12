// Chapter18_05_app/main.c
// fflush 예제

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

int main() {
	printf("작업 진행");

	for (int i = 0; i < 10; i++) {
		printf(".");
		fflush(stdout);		// 현재 버퍼에 남은 데이터 한 번에 처리.
		Sleep(500);			// 0.5초씩 대기
	}

	printf("완료.");

	return 0;
}
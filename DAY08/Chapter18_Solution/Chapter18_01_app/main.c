// Chapter18_01_app/main.c
// 파일 입출력

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE* fp;		// 파일 포인터

	// 파일 열기
	fp = fopen("C:\\test.txt", "r");	// r : 읽기 , w : 쓰기, a : 내용 추가

	if (fp == NULL) {
		printf("파일이 열리지 않았습니다.\n");
		exit(1);
	}

	printf("파일이 열렸습니다.\n");

	// 파일 닫기
	fclose(fp);

	return 0;
}
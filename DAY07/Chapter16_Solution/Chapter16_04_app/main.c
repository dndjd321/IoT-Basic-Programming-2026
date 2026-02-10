// Chapter16_04_app/main.c
// 동적 할당 예제

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char temp[80];		// 최대길이 80까지 받을 수 있는 문자열
	char* str[3];		// 동적 할당할 포인터 배열
	int i;

	for (i = 0; i < 3; i++) {
		printf("문자열 입력 : ");
		gets(temp);
		//printf("입력한 문자열 : %s\n", temp);
		str[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(str[i], temp);
	}

	for (i = 0; i < 3; i++) {
		printf("%s\n", str[i]);
	}

	// free() 사용하여 메모리 해제
	for (i = 0; i < 3;i++) {
		free(str[i]);	// free를 안하면 메모리 누수 (memory leak) 발생
	}

	return 0;
}
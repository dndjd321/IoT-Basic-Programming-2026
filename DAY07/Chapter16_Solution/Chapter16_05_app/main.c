// Chapter16_05_app/main.c
// 동적할당 처리 함수

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_str(char**);
void print_str2(char** ps, int count);

int main() {

	char temp[81];
	char* str[21] = { 0 };
	int i = 0;

	while (i < 20) {
		printf("문자열 입력 : ");
		gets(temp);

		// 문자열이 end와 동일하면 입력이 종료되도록 조건 체크 후 True이면 break로 탈출
		if (strcmp(temp, "end") == 0) break;

		str[i] = (char*)malloc(strlen(temp) + 1);	// \0 까지 포함. 동적메모리할당
		strcpy(str[i], temp);
		i++;
	}

	// 입력문자열 출력 함수
	print_str(str);	// str 전체를 매개변수로 전달. 배열의 주소
	print_str2(str, i);

	for (i = 0; str[i] != NULL; i++) {
		free(str[i]);	// 메모리 해제
	}

	return 0;
}

void print_str(char** ps) {
	while (*ps != NULL) {
		printf("%s\n", *ps);
		ps++;
	}
}

void print_str2(char** ps, int count) {
	int i;
	
	for (i = 0; i < count; i++) {
		printf("# %s\n", *(ps + i));
	}
}
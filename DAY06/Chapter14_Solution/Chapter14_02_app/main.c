// Chapter14_02_app/main.c
// 포인터 배열

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char* panimal[5];	// 동물 5마리 입력하는데, 문자열을 포인터로 사용
	int i;

	panimal[0] = "강아지";
	panimal[1] = "고슴도치";
	panimal[2] = "뱀";
	panimal[3] = "사자";
	panimal[4] = "긴꼬리원숭이";

	for (i = 0; i < sizeof(panimal) / sizeof(panimal[0]); i++) {
		printf("%s\n", panimal[i]);
	}

	return 0;
}
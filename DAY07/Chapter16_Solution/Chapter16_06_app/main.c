// Chapter16_06_app/main.c
// Console Program 명령행 인수

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// main 함수. Entry Point(진입점)
// argc : 인수 개수, argv : 인자 (문자열)의 배열
// ex ) .\Chapter16_06_app.exe help
// argc = 2
// argv = [".\Chapter16_06_app.exe", "help"]
int main(int argc, char** argv) {

	int i = 0;
	/*for (i = 0; i < argc; i++) {
		printf("%s\n", *(argv + i));
	}*/

	// 입력받는 문자열마다 여러가지 처리되는 프로그램을 개발 가능

	if (argc < 2) {
		printf("mygit: 명령어가 필요합니다.\n");
		printf("사용법: mygit <command> [options]\n");
		return 0;
	}

	/* git init */
	if (strcmp(argv[1], "init") == 0) {
		printf("git 저장소 초기화.");
	}
	else if (strcmp(argv[1], "commit") == 0) {
		if (argc >= 4 && strcmp(argv[2], "-m") == 0) {
			printf("git commit message: '%s'\n", argv[3]);
			printf("[main abc1234] commit 완료.\n");
		}
		else {
			printf("오류 발생.\n");
		}
	}
	else {
		printf("mygit: 알 수 없는 명령어 '%s'\n", argv[1]);
	}

	return 0;
}
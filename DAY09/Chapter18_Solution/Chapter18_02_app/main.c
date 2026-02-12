// Chapter18_02_app/main.c
// 파일 입출력

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>

int main() {
	char cwd[256];
	char str[80];
	char* res;

	_getcwd(cwd, sizeof(cwd));
	printf("현재 작업(프로젝트) 폴더 : %s\n", cwd);

	// 여기서부터 txt파일 복사
	FILE* fp, *ofp;
	fp = fopen("./data/sample.txt", "r");
	if (fp == NULL) {
		printf("파일 열기 실패.\n");
		return 1; //exit(1)과 동일한 기능
	}
	else {
		printf("파일 열기 성공\n");
	}

	// 파일 복사용 오픈
	ofp = fopen("./data/copy.txt", "w");
	if (ofp == NULL) {
		printf("출력파일 열기 실패.\n");
		return 1; //exit(1)과 동일한 기능
	}
	
	while (1) {
		res = fgets(str, sizeof(str), fp);
		if (res == NULL) {
			break;
		}

		printf("한줄 쓰기 -> %s\n", str);
		//str[strlen(str) - 1] = '\0';
		fputs(str, ofp);
		//fputs(" ", ofp);
	}

	fclose(fp);
	fclose(ofp);

	return 0;
}
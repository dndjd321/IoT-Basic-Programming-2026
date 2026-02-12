// Chapter18_04_app/main.c
// 파일 입출력 추가 내용

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	FILE* fp;

	char str[30];

	// w, a 는 파일이 없으면 자동으로 생성함.
	// r 은 파일 읽기 기능이므로 파일이 없으면 생성하지 않고 읽지 못함.
	fp = fopen("./fruit.txt", "a+");	// 기존 텍스트에 추가, + 읽고 쓰기
	if (fp == NULL) {
		printf("파일 오픈 실패.\n");
		exit(1);
	}

	// 실제 작업
	while (1) {
		printf("과일 이름 입력 : ");
		scanf("%s", str);	// 키보드 입력

		if (strcmp(str, "end") == 0) {
			break;
		}
		else if (strcmp(str, "list") == 0) {
			fseek(fp, 0, SEEK_SET);	// 파일 포인터 => 버퍼(파일 스트림)의 맨 처음으로 이동

			while (1) {
				fgets(str, sizeof(str), fp); // 파일 포인터에서 첫 줄을 읽어옴
				if(feof(fp)) {	// 읽은 줄이 텍스트 파일 마지막(EOF) 이면 break;
					break;
				}
				printf("%s",str);	// \n 이 없는 이유는 텍스트 파일 자체에 포함이 되어있기 때문임.
			}
		}
		else {
			fprintf(fp, "%s\n", str);	// fruis.txt 파일에 쓰기
		}
	}

	fclose(fp);
	printf("파일 처리 완료.\n");

	return 0;
}
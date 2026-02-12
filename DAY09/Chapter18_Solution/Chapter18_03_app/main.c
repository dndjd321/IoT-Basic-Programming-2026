// Chapter18_03_app/main.c
// 파일 입출력

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>	// OS 관련 또는 코드 페이지 인코딩 해결 

int main() {
	// console 출력, 입력을 UTF-8(65001)로 고정하기 위한 설정
	SetConsoleOutputCP(65001);		// 콘솔 출력 코드페이지
	SetConsoleCP(65001);			// 콘솔 자체 코드페이지

	FILE* ifp, *ofp;

	// 텍스트 내 포맷에 맞춰서 변수 선언
	char name[20];
	int kor, eng, math;
	int total;
	double avg;
	int res;

	ifp = fopen("./original.txt", "r");
	if (ifp == NULL) {
		printf(u8"입력파일 읽기 실패하였습니다.\n");	// u8 : 문자열을 utf8로 변환 출력하기위함.
		exit(1);
	}

	ofp = fopen("./copy.txt", "w");	// w 쓰기 모드는 파일이 없으면 자동 생성

	if (ifp == NULL) {
		printf("출력파일 생성 실패하였습니다.\n");
		exit(1);
	}

	while (1) {
		// 입력 파일 포인터에서 내용을 읽어서 한 줄 씩 각 변수에 할당하기
		res = fscanf(ifp, "%s %d %d %d", name, &kor, &eng, &math);
		if(res == EOF){	// 파일 데이터의 마지막까지 다 읽었을 경우 EOF 진입
			break;
		}

		total = kor + eng + math;
		avg = total / 3.0;

		printf("%s%5d%7.2lf\n", name, total, avg);	// console에 출력
		fprintf(ofp, "%s%5d%7.2lf\n", name, total, avg);
	}

	printf("파일 복사 완료.\n");
	fclose(ifp);
	fclose(ofp);

	return 0;
}
// Chapter11_02_app/main.c
// 문자 입력 실수

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char c1, c2, c3;

	//scanf("%c%c", &c1, &c2);	// a와 Enter를 키보드 입력 시, c1 = 'a', c2 = '\n'이 입력됨.
	//printf("[%c%c]",c1, c2);

	// getchar(), putchar() 함수 사용하여 글자 하나를 입력 및 출력
	//c3 = getchar();	// getchar() 함수는 앞선 입력의 \n도 들어갈 수 있음.
	//printf("입력 값 -> %c\n", c3);
	//putchar(c3);

	// 주석변환 토글 단축키 : Ctrl + /
	// 주석변환 단축키		: Ctrl + K + C
	// 주석해제 단축키		: Ctrl + K + U

	int num, grade;		// 학번, 학점

	printf("학번 입력 : ");
	scanf("%d", &num);		// 학번 입력
	getchar();				// 키보드 버퍼의 내용은 읽어옴.
							// 그냥 사라짐. buffer clear -> \n 만 지움. space는 해결 안 됨.
	printf("학점 입력 : ");
	grade = getchar();		// 학점 입력

	printf("학번 : %d, 학점 : %c\n", num , grade);


	return 0;
}
// Chapter08_Quiz_app/main.c

// 대소문자 변환 프로그램
// Don't Worry, Be Happy~ --> don't worry, be happy 로 변환

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char str[80];
	int i = 0;
	int count = sizeof(str) / sizeof(str[0]);
	int pos = 0;	// 문자열에서 \0값이 처음 나오는 위치 ( Array Index )
	int lowerNum = 0;	// 대문자에서 소문자로 바뀐 개수
	int upperNum = 0;	// 소문자에서 대문자로 바뀐 개수

	printf("문자열 입력 : ");
	gets(str);

	// pos 값 할당하기 - 문자열 끝나는 위치 찾기
	for (i = 0; i < count; i++) {
		if (str[i] == '\0') {
			pos = i;
			break;
		}
	}

	// 대문자 -> 소문자
	// str 글자 수만큼만 반복하여 대문자를 소문자로 변환하는 반복문 로직
	/*for (i = 0; i < pos; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') 
		{
			str[i] += 32; 
			lowerNum++;
		}
	}*/

	// 소문자 -> 대문자
	// str 글자 수만큼만 반복하여 소문자를 대문자로 변환하는 반복문 로직
	for (i = 0; i < pos; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') 
		{
			str[i] -= 32; 
			upperNum++;
		}
	}

	printf("바뀐 문장 : ");
	puts(str);
	//printf("\n변경된 문자 개수 : %d\n", lowerNum);
	printf("\n변경된 문자 개수 : %d\n", upperNum);

	return 0;
}
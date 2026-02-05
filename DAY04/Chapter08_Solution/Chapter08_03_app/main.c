// Chapter08_03_app/main.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>	// 문자열 복사 함수를 사용하기 위해

int main() {
	char str[80] = "applejam";	// str[8] 부터는 \0(널 문자로) 자동 초기화 됨.
	char str2[80];

	printf("최초 문자열 : %s\n", str);
	
	//printf("문자열 입력 : ");
	//scanf("%s", str);
	//// 첨자[i]를 사용하지 않으면
	//// 배열의 이름은 배열의 주소를 가리키는 포인터 상수로 취급된다.

	strcpy(str, "grape");

	printf("입력 후 문자열 : %s\n", str);

	strcpy(str2, str);
	printf("str2 : %s", str2);

	return 0;
}
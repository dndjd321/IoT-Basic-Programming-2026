// Chapter12_02_app/main.c
// 문자열고 포인터, 문자열 함수

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>	// 문자열 함수를 사용하기 위한 헤더 파일

int main() {
	char str1[80] = "strawberry";
	char str2[80] = "apple";
	char* ps1 = "banana";
	char* ps2 = str2;

#pragma region strcpy 함수
	printf("최초 문자열 : %s\n", str1);

	// str1에 str2 문자열 내용을 복사.
	strcpy(str1, str2);			
	printf("변경된 문자열 : %s\n", str1);
	
	strcpy(str1, ps1);	
	printf("변경된 문자열 : %s\n", str1);

	strcpy(str1, ps2);	
	printf("변경된 문자열 : %s\n", str1);

	// 문자열 상수도 가능.
	strcpy(str1, "appleMango");	
	printf("변경된 문자열 : %s\n", str1);

	// 문자형 배열 str2에 바로 값 할당은 불가하지만
	// 문자형 포인터 ps2에는 바로 값 할당 가능
	// str2 = "abc"; -> X
	// ps2 = "abc"; -> O
#pragma endregion

#pragma region strncpy 함수
	// 원하는 개수의 문자를 복사하는 함수
	char str3[20] = "mango-tree";

	strncpy(str3, "apple-pie", 5);
	printf("변경된 str3 : %s\n", str3);
#pragma endregion

#pragma region strcat, strncat 함수
	// string concatenate() : 앞 매개변수 값 뒤에 뒤 매개변수 값 이어붙히는 함수
	char str4[80] = "straw";

	strcat(str4,"berry");
	printf("변경된 str4 : %s\n", str4);
	strncat(str4, "piece", 3);
	printf("변경된 str4 : %s\n", str4);

#pragma endregion

#pragma region strlen 함수
	// string 문자열 길이 확인하는 함수
	// C에서 한글 글자 길이는 한 글자당 2로 지정
	printf("str1 %s의 문자열 길이 : %zu\n", str1, strlen(str1));
	printf("str2 %s의 문자열 길이 : %zu\n", str2, strlen(str2));
	printf("str3 %s의 문자열 길이 : %zu\n", str3, strlen(str3));
	printf("str4 %s의 문자열 길이 : %zu\n", str4, strlen(str4));
#pragma endregion

#pragma region strcmp, strncmp 함수
	// string 문자열을 비교하는 함수
	char str5[80] = "pear";
	char str6[80] = "peach";

	// strcmp(str5, str6) = 1 (str5가 str6보다 사전에 나중에 나올경우)
	// strcmp(str5, str6) = 0 (같은 문자열인 경우)
	// strcmp(str5, str6) = -1 (str5가 str6보다 사전에 먼저 나올경우)
	// printf("사전에 나중에 나오는 과일 : %d", strcmp(str5, str6));

	if ((strcmp(str5, str6)) > 0) {
		printf("사전에 나중에 나오는 과일 : %s\n", str5);
	}
	else if ((strcmp(str5, str6)) < 0) {
		printf("사전에 나중에 나오는 과일 : %s\n", str6);
	}
	else {
		printf("같은 단어 입니다.\n");
	}

	// "pear" 와 "peach"를 앞 3글자만 비교
	int result = strncmp(str5, str6, 3);
	if (result > 0) {
		printf("앞 3글자 기준 사전에 나중에 나오는 단어 : %s\n", str5);
	}
	else if (result < 0) {
		printf("앞 3글자 기준 사전에 나중에 나오는 단어 : %s\n", str6);
	}
	else {
		printf("앞 3글자가 동일합니다.\n");
	}

#pragma endregion


	return 0;
}
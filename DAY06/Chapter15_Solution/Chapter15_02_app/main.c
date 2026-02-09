// Chapter15_02_app/main.c
// 이중포인터 활용

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void swap_ptr(char** ppa, char** ppb);		// 포인터 값을 바꾸는 매개변수
void print_str(char** pps, int count);


int main() {
	char* pa = "success";
	char* pb = "failure";

	printf("pa -> %s, pb -> %s\n", pa, pb);	// 변경 전 문자열

	swap_ptr(&pa, &pb);

	printf("pa -> %s, pb -> %s\n", pa, pb);	// 변경 후 문자열

	// 포인터배열
	// char* ptr_animal[] != char** ptr_animal
	char* ptr_animal[] = { "eagle","tiger","lion","squirrel" };
	int count = sizeof(ptr_animal) / sizeof(ptr_animal[0]);

	print_str(ptr_animal, count);

	return 0;
}

void swap_ptr(char **ppa, char ** ppb) {
	char* ptemp;

	ptemp = *ppa;		// ppa의 주소를 ptemp에 전달 -> "success"의 주소
	*ppa = *ppb;		// ppb의 주소를 ppa 에 전달
	*ppb = ptemp;
}

// pps -> 2차원 문자배열과 유사
void print_str(char** pps, int count) {

	int i;

	for (i = 0; i < count; i++) {
		printf("%s\n", pps[i]);	//*(pps+i) 와 동일
	}
}
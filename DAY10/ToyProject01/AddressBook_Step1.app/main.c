// AddressBook_Step1.app/main.c
// 주소록 프로그램

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// 함수 선언
static void printMenu();
static int readMenu();


int main() {
	int choice = 0;

	while (1) {	// 무한루프 : 
		// 메뉴 출력
		printMenu();
		
		choice = readMenu();

		switch (choice) {
			case 1:
				printf("%s\n", "[ADD] 연락처 추가 ( 기능 구현 요구 )");
				break;
			case 2:
				puts("[LIST] 연락처 목록");
				break;
			case 3:
				puts("[SEARCH] 연락처 검색");
				break;
			case 4:
				puts("[EDIT] 연락처 수정");
				break;
			case 5:
				puts("[DELETE] 연락처 삭제");
				break;
			case 6:
				printf("프로그램 종료");
				return 0;
			default:
				printf("메뉴는 1~6사이 입니다.");
				break;
		}

		puts("");
	}

	return 0; 
}

static void printMenu() {
	puts("========================================");
	puts("=      주소록 프로그램 ( STEP 1 )      =");
	puts("========================================");
	puts("1. 추가");
	puts("2. 목록");
	puts("3. 검색");
	puts("4. 수정");
	puts("5. 삭제");
	puts("6. 종료");
	puts("========================================");

}

static int readMenu() {
	int choice, ch;

	printf("선택 > ");
	if (scanf("%d", &choice) != 1) {
		// 버퍼에 남아있는 '\n' 값 제거해주기
		while ((ch = getchar()) != '\n' && ch != EOF) {}
		return -1;
	}

	// scanf 뒤에 있는 버퍼에 개행문자(엔터값) 제거
	while ((ch = getchar()) != '\n' && ch != EOF) {}

	return choice;
}
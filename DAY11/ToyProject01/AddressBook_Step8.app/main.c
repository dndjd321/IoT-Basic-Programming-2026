// AddressBook_Step8.app/main.c
// 주소록 프로그램 Step8
#define _CRT_SECURE_NO_WARNINGS
#include "AddressBook.h"
#include <stdlib.h>
#include <stdio.h>

#pragma region main 함수

static void clearScreen() {
	system("cls");	// 화면 클리어
}

static void pauseEnter() {
	puts("\n계속하려면 Enter...");
	getchar();
}

int main() {
	int choice = 0;

	if (!ab_init()) {
		// 초기화 실패 시 프로그램 종료
		return 1;
	}
	
	loadContacts("contacts.txt");

	while (1) {	// 무한루프 : 
		clearScreen();

		// 메뉴 출력
		printMenu();

		choice = readMenu();

		switch (choice) {
		case 1:	// 연락처 추가
			addContact();
			break;
		case 2:	// 연락처 목록
			listContacts();
			break;
		case 3:	// 연락처 검색
			searchContact();
			break;
		case 4:	// 연락처 수정
			updateContact();
			break;
		case 5:	// 연락처 삭제
			deleteContact();
			break;
		case 6:	// 연락처 정렬
			sortByName();
			break;
		case 7:	// 프로그램 종료
			saveContacts("contacts.txt");
			// 프로그램 종료 전 메모리 해제
			ab_free();
			printf("프로그램 종료");
			return 0;
		//case 7:	// 연락처 저장
		//	saveContacts("contacts.txt");
		//	break;
		//case 8:	// 연락처 불러오기
		//	loadContacts("contacts.txt");
		//	break;
		default:
			printf("메뉴는 1~7사이 입니다.");
			break;
		}

		pauseEnter();
	}

	return 0;
}

#pragma endregion
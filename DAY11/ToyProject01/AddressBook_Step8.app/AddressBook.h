#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#pragma region define 영역

#define _CRT_SECURE_NO_WARNINGS
// 재정의 및 매크로 선언

//#define MAX_CONTACTS 100	// 최대 100명의 주소록
#define INIT_CAPACITY 10	// 초기값 10으로 설정
#define NAME_LEN 31			// 이름 최대 길이
#define PHONE_LEN 21		// 번호 최대 길이
#define EMAIL_LEN 65		// 메일 최대 길이
#define ADDR_LEN 121		// 주소 최대 길이
#define MEMO_LEN 31			// 메모 최대 길이

#pragma endregion

#pragma region include 영역
// 헤더 파일 선언
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma endregion

#pragma region struct 영역

// 구조체 선언 및 정의
typedef struct _contact {
	char name[NAME_LEN];
	char phone[PHONE_LEN];
	char addr[ADDR_LEN];
	char email[EMAIL_LEN];
	char memo[MEMO_LEN];
} Contact;

#pragma endregion

#endif

// 외부 main.c에서 호출할 함수리스트

#pragma region 함수 영역

// 함수 선언
void printMenu();
int readMenu();
void addContact();
void listContacts();
void searchContact();
void updateContact();
void deleteContact();
int saveContacts(const char* fileName);
int loadContacts(const char* fileName);
void sortByName();
int ab_init();			// 주소록 초기화
void ab_free();			// 주소록 메모리 해제



#pragma endregion
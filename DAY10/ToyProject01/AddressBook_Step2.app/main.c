// AddressBook_Step2.app/main.c
// 주소록 프로그램 Step2

// 재정의 선언
#define _CRT_SECURE_NO_WARNINGS
#define MAX_CONTACTS 100	// 최대 100명의 주소록
#define NAME_LEN 31			// 이름 최대 길이
#define PHONE_LEN 21		// 번호 최대 길이
#define EMAIL_LEN 65		// 메일 최대 길이
#define ADDR_LEN 121		// 주소 최대 길이
#define MEMO_LEN 31			// 메모 최대 길이

// 구조체 선언 및 정의
typedef struct _contact {
	char name[NAME_LEN];
	char phone[PHONE_LEN];
	char addr[ADDR_LEN];
	char email[EMAIL_LEN];
	char memo[MEMO_LEN];
} Contact;

// 헤더 파일 선언
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 변수 선언
static Contact contacts[MAX_CONTACTS];
static int count = 0;

// 함수 선언
static void printMenu();
static int readMenu();
static void readLine(char* buf, int size);
static void addContact();
static void listContacts();

int main() {
	int choice = 0;

	while (1) {	// 무한루프 : 
		// 메뉴 출력
		printMenu();
		
		choice = readMenu();

		switch (choice) {
			case 1:
				//printf("%s\n", "[ADD] 연락처 추가 ( 기능 구현 요구 )");
				// 연락처 추가 기능 구현 함수
				addContact();	
				break;
			case 2:
				//puts("[LIST] 연락처 목록");
				// 연락처 목록 기능 구현 함수
				listContacts();	
				break;
			case 3:
				puts("[SEARCH] 연락처 검색 ( 다음 스텝 )");
				break;
			case 4:
				puts("[EDIT] 연락처 수정 ( 다음 스텝 )");
				break;
			case 5:
				puts("[DELETE] 연락처 삭제 ( 다음 스텝 )");
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

// console에 printMenu 내용 출력
static void printMenu() {
	puts("========================================");
	puts("=      주소록 프로그램 ( STEP 2 )      =");
	puts("========================================");
	puts("1. 추가");
	puts("2. 목록");
	puts("3. 검색(미구현)");
	puts("4. 수정(미구현)");
	puts("5. 삭제(미구현)");
	puts("6. 종료");
	puts("========================================");

}

// 사용자가 입력한 숫자 값 읽어서 int값 반환하기
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

// fgets() 로 입력할 때 문제가 발생하지 않도록, 문자열 끝에 '\n'을 제거
static void readLine(char* buf, int size) {
	if (fgets(buf, size, stdin) == NULL) {
		buf[0] = '\0';
		return;
	}

	// 문자열 끝에 있는 '\n'을 '\0'으로 변경. 
	// strcspn(char* c1, char* c2) => c1 문자열 내에서 c2 를 찾아서 그 위치값을 반환해주는 함수
	// 결국 아래 내용으로 보면 buf에서 "\n" 이 있는 위치 index를 반환하여 buf[index] 값을 ='\0'으로 변경함.
	// 예시 : buf = "Helo World!\n" => "Helo World!\0"
	buf[strcspn(buf, "\n")] = '\0';	
}

// 메뉴 1번 기능, 연락처 추가
static void addContact() {
	if (count >= MAX_CONTACTS) {
		puts("주소록 최대인원 100명에 도달했습니다.");
		return;
	}

	puts("[ADD] 새 연락처 입력");
	printf("이름[최대 10자] : ");
	readLine(contacts[count].name, NAME_LEN);

	printf("전화번호[최대 20자] : ");
	readLine(contacts[count].phone, PHONE_LEN);

	printf("주소[최대 40자] : ");
	readLine(contacts[count].addr, ADDR_LEN);

	printf("이메일 : ");
	readLine(contacts[count].email, EMAIL_LEN);

	printf("메모[최대 10자] : ");
	readLine(contacts[count].memo, MEMO_LEN);

	// 추가한 내용 로컬 저장 가능하도록 하기

	count++;
	puts("추가 완료.");
}

// 메뉴 2번 기능, 연락처 목록
static void listContacts() {
	int i;

	if (count <= 0) {
		puts("[LIST] 저장된 연락처가 없습니다.");
		return;
	}

	puts("[LIST] 연락처 목록");
	puts("------------------------------------------------------------------------------------------------------------------------");
	printf("총 연락처 개수 : %d\n", count);
	puts("------------------------------------------------------------------------------------------------------------------------");
	printf("%4s | %-10s | %-19s | %-34s | %-31s | %-15s\n", 
		"순번", "이름", "전화번호", "주소", "이메일", "메모");
	puts("------------------------------------------------------------------------------------------------------------------------");
	for (i = 0; i < count; i++) {
		printf("%4d | %-11s | %-15s | %-35s | %-28s | %-15s\n", 
			(i+1), contacts[i].name, contacts[i].phone, 
			contacts[i].addr, contacts[i].email, contacts[i].memo);
	}
	puts("------------------------------------------------------------------------------------------------------------------------");

	return;
}
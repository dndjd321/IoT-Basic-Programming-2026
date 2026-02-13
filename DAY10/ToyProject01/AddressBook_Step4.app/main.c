// AddressBook_Step4.app/main.c
// 주소록 프로그램 Step4

#pragma region define 영역

// 재정의 및 매크로 선언
#define _CRT_SECURE_NO_WARNINGS
#define MAX_CONTACTS 100	// 최대 100명의 주소록
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

#pragma region 변수 영역

// 변수 선언
static Contact contacts[MAX_CONTACTS];
static int count = 0;

#pragma endregion

#pragma region 함수 영역

// 함수 선언
static void printMenu();
static int readMenu();
static void readLine(char* buf, int size);
static void addContact();
static void listContacts();
static void searchContact();
static void printContact(int idx);
static void updateContact();
static void deleteContact();

#pragma endregion

#pragma region main 함수

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
			//puts("[SEARCH] 연락처 검색");
			searchContact();
			break;
		case 4:
			//puts("[EDIT] 연락처 수정");
			updateContact();
			break;
		case 5:
			//puts("[DELETE] 연락처 삭제");
			deleteContact();
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

#pragma endregion

#pragma region 함수 정의 영역

// console에 printMenu 내용 출력
static void printMenu() {
	puts("========================================");
	puts("=      주소록 프로그램 ( STEP 4 )      =");
	puts("========================================");
	puts("1. 추가");
	puts("2. 목록");
	puts("3. 검색");
	puts("4. 수정");
	puts("5. 삭제");
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
			(i + 1), contacts[i].name, contacts[i].phone,
			contacts[i].addr, contacts[i].email, contacts[i].memo);
	}
	puts("------------------------------------------------------------------------------------------------------------------------");

	return;
}

// 메뉴 3번 기능, 연락처 검색 기능
static void searchContact() {
	char keyword[NAME_LEN];
	int found = 0;
	int i;

	// 연락처 내용이 없을 경우, 검색 메뉴 종료 -> 메인화면으로 다시 이동
	if (count == 0) {
		puts("검색할 연락처가 없습니다.");
		return;
	}

	printf("검색할 이름 입력 : ");
	readLine(keyword, NAME_LEN);

	if (strlen(keyword) == 0) {
		puts("검색할 이름이 없습니다.");
		return;
	}

	puts("검색 결과");
	puts("----------------------------------------");

	for (i = 0; i < count; i++) {
		// strcmp와 유사한 기능
		// strstr(찾을 문자열, 찾는 문자열) 같은 문자열이 있으면 그 문자열 리턴
		if (strstr(contacts[i].name, keyword) != NULL) {
			printf("순번 : %d\n", i + 1);
			// 상세출력
			printContact(i);
			puts("----------------------------------------");

			found = 1;
		}
	}

	if (found < 1) {
		puts("일치하는 연락처가 없습니다.");
	}

}

// 연락처 검색 후 출력하는 함수
static void printContact(int idx) {
	printf("이름 : %s\n", contacts[idx].name);
	printf("전화 : %s\n", contacts[idx].phone);
	printf("주소 : %s\n", contacts[idx].addr);
	printf("메일 : %s\n", contacts[idx].email);
	printf("메모 : %s\n", contacts[idx].memo);
}

// 메뉴 4번 기능, 연락처 내용 수정
static void updateContact() {
	char buf[MEMO_LEN];
	int idx, ch;

	if (count == 0) {
		puts("수정할 연락처가 없습니다.");
		return;
	}

	printf("[UPDATE] 수정할 번호 ( 1 ~ %d ) > ", count);

	if (scanf("%d", &idx) != 1) {	// 입력 실패
		while ((ch = getchar()) != '\n' && ch != EOF) {}
		puts("숫자 입력 요망");
		return;
	}

	// 이전 버퍼에 남아있는 데이터 삭제 기능
	while ((ch = getchar()) != '\n' && ch != EOF) {}

	if (idx < 1 || idx > count) {
		puts("입력범위 초과");
		return;
	}

	puts("현재 정보");
	// 실제 인덱스는 0,1,2 이지만 검색 순번은 1,2,3을 사용하기 때문에 idx-1 처리
	printContact(idx - 1);
	puts("----------------------------------------");

	// 내용 수정 로직
	puts("새 값 입력 (엔터만 입력하면 기존값 유지)");

	printf("이름 (%s) > ", contacts[idx - 1].name);
	readLine(buf, NAME_LEN);
	if (buf[0] != '\0') {	// 엔터만 친게 아닌경우, 내용을 입력했을 경우
		strncpy(contacts[idx - 1].name, buf, NAME_LEN);
		// 글자를 MAX로 적으면 \0이 들어가야 문자열 끝을 알려줌.
		contacts[idx - 1].name[NAME_LEN - 1] = '\0';
	}

	printf("전화 (%s) > ", contacts[idx - 1].phone);
	readLine(buf, PHONE_LEN);
	if (buf[0] != '\0') {	// 엔터만 친게 아닌경우, 내용을 입력했을 경우
		strncpy(contacts[idx - 1].phone, buf, PHONE_LEN);
		contacts[idx - 1].phone[PHONE_LEN - 1] = '\0';
	}

	printf("주소 (%s) > ", contacts[idx - 1].addr);
	readLine(buf, ADDR_LEN);
	if (buf[0] != '\0') {	// 엔터만 친게 아닌경우, 내용을 입력했을 경우
		strncpy(contacts[idx - 1].addr, buf, ADDR_LEN);
		contacts[idx - 1].addr[ADDR_LEN - 1] = '\0';
	}

	printf("메일 (%s) > ", contacts[idx - 1].email);
	readLine(buf, EMAIL_LEN);
	if (buf[0] != '\0') {	// 엔터만 친게 아닌경우, 내용을 입력했을 경우
		strncpy(contacts[idx - 1].email, buf, EMAIL_LEN);
		contacts[idx - 1].email[EMAIL_LEN - 1] = '\0';
	}

	printf("메모 (%s) > ", contacts[idx - 1].memo);
	readLine(buf, MEMO_LEN);
	if (buf[0] != '\0') {	// 엔터만 친게 아닌경우, 내용을 입력했을 경우
		strncpy(contacts[idx - 1].memo, buf, MEMO_LEN);
		contacts[idx - 1].memo[MEMO_LEN - 1] = '\0';
	}

	puts("수정 완료.");
}

// 메뉴 5번 기능, 연락처 삭제
static void deleteContact() {

	int idx, i, ch;
	char yn[8];

	if (count == 0) {
		puts("삭제할 연락처가 없습니다.");
		return;
	}

	printf("[DELETE] 삭제할 번호 ( 1 ~ %d ) > ", count);

	if (scanf("%d", &idx) != 1) {	// 입력 실패
		while ((ch = getchar()) != '\n' && ch != EOF) {}
		puts("숫자 입력 요망");
		return;
	}

	// 이전 버퍼에 남아있는 데이터 삭제 기능
	while ((ch = getchar()) != '\n' && ch != EOF) {}

	if (idx < 1 || idx > count) {
		puts("입력범위 초과");
		return;
	}

	puts("삭제할 정보");
	printContact(idx - 1);
	puts("----------------------------------------");

	printf("정말 삭제하시겠습니까? (y/n) > ");
	readLine(yn, (int)sizeof(yn));

	if (!(yn[0] == 'y' || yn[0] == 'Y')) {
		puts("삭제를 취소합니다.");
		return;
	}

	// 현재 삭제할 값 이후의 배열오소를 앞으로 당기는 작업 ( 다시 정렬하기 )
	for (i = idx - 1; i < count - 1; i++) {
		contacts[i] = contacts[i + 1];
	}

	count--;

	puts("삭제 완료.");

}

#pragma endregion



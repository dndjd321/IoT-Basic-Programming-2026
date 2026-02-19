#define _CRT_SECURE_NO_WARNINGS
#include "AddressBook.h"

#pragma region 변수 영역

// 변수 선언
//static Contact contacts[MAX_CONTACTS];	// 배열에서

static Contact* contacts = NULL;				// 동적배열로 변경
static int count = 0;
static int capacity = 0;

#pragma endregion

#pragma region 내부함수선언

static void readLine(char* buf, int size);
static void printContact(int idx);
static void trimNewLine(char* s);	// 줄바꿈 제거기능 함수
static int containsPipe(const char* s);
static int findByPhone(const char* phone);
static int cmpContactName(const void* a, const void* b);
static int ab_ensureCapacity(int need);	// 주소록 용량 확장

#pragma endregion

#pragma region 함수 정의 영역

// console에 printMenu 내용 출력
void printMenu() {
	puts("========================================");
	puts("=      주소록 프로그램 ( STEP 8 )      =");
	puts("========================================");
	puts("1. 추가");
	puts("2. 목록");
	puts("3. 검색");
	puts("4. 수정");
	puts("5. 삭제");
	puts("6. 정렬");
	puts("7. 종료");
	//puts("7. 저장");
	//puts("8. 로드");
	puts("========================================");

}

// 사용자가 입력한 숫자 값 읽어서 int값 반환하기
int readMenu() {
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
	trimNewLine(buf);
}

// 문자열 마지막에 엔터가 있으면 제거하는 함수
static void trimNewLine(char* s) {
	s[strcspn(s, "\n")] = '\0';
}

// 메뉴 1번 기능, 연락처 추가
void addContact() {
	/*if (count >= MAX_CONTACTS) {
		puts("주소록 최대인원 100명에 도달했습니다.");
		return;
	}*/

	if (!ab_ensureCapacity(count + 1)) {
		puts("메모리 추가 실패");
		return;
	}

	puts("[ADD] 새 연락처 입력");
	printf("이름[최대 10자] : ");
	readLine(contacts[count].name, NAME_LEN);
	if (containsPipe(contacts[count].name)) {
		puts("'|' 문자는 사용할 수 없습니다. 다시 추가해주세요.");
		return;
	}

	printf("전화번호[최대 20자] : ");
	readLine(contacts[count].phone, PHONE_LEN);
	if (containsPipe(contacts[count].phone)) {
		puts("'|' 문자는 사용할 수 없습니다. 다시 추가해주세요.");
		return;
	}

	if (strlen(contacts[count].phone) == 0) {
		puts("전화번호는 필수입니다.");
		return;
	}

	{	// 영역을 구분짓는 코드블럭
		int dup = findByPhone(contacts[count].phone);
		if (dup != -1) {
			printf("동일 전화번호 존재 (순번: %3d, 이름: %10s)\n", dup + 1, contacts[dup].name);
			puts("추가를 취소합니다.");
			return;
		}
	}

	printf("주소[최대 40자] : ");
	readLine(contacts[count].addr, ADDR_LEN);
	if (containsPipe(contacts[count].addr)) {
		puts("'|' 문자는 사용할 수 없습니다. 다시 추가해주세요.");
		return;
	}

	printf("이메일 : ");
	readLine(contacts[count].email, EMAIL_LEN);
	if (containsPipe(contacts[count].email)) {
		puts("'|' 문자는 사용할 수 없습니다. 다시 추가해주세요.");
		return;
	}

	printf("메모[최대 10자] : ");
	readLine(contacts[count].memo, MEMO_LEN);
	if (containsPipe(contacts[count].memo)) {
		puts("'|' 문자는 사용할 수 없습니다. 다시 추가해주세요.");
		return;
	}

	// 추가한 내용 로컬 저장 가능하도록 하기

	count++;
	puts("추가 완료.");
}

// 메뉴 2번 기능, 연락처 목록
void listContacts() {
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
void searchContact() {
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
void updateContact() {
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

// 연락처 삭제
void deleteContact() {

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

// 연락처 저장
int saveContacts(const char* fileName) {
	FILE* fp = fopen(fileName, "w");	// 쓰기 모드로 파일 열기

	if (!fp) {
		puts("파일 저장에 실패하였습니다. >> 경로 또는 권한 확인 필요.");
		return 0;
	}

	// 저장 작업
	for (int i = 0; i < count; i++) {
		// 구분자로 | 사용
		fprintf(fp, "%s|%s|%s|%s|%s\n",
			contacts[i].name,
			contacts[i].phone,
			contacts[i].addr,
			contacts[i].email,
			contacts[i].memo);
	}

	fclose(fp);
	puts("연락처 저장 완료하였습니다.");

	return 1;	// 성공 시 반환 값
}

// 연락처 로드
int loadContacts(const char* fileName) {
	FILE* fp = fopen(fileName, "r");
	char line[600];

	if (!fp) {
		puts("불러올 파일이 없습니다.");
		return 0;
	}

	count = 0;

	while (fgets(line, sizeof(line), fp) != NULL) {
		char* name;
		char* phone;
		char* addr;
		char* email;
		char* memo;

		trimNewLine(line);

		// 구분자 |로 문자열 분리
		name = strtok(line, "|");
		phone = strtok(NULL, "|");
		addr = strtok(NULL, "|");
		email = strtok(NULL, "|");
		memo = strtok(NULL, "|");

		// 하나라도 값이 없다면 continue 처리
		if (!name || !phone || !addr || !email || !memo) continue;
		// count가 100이 쌓이면 break 처리
		// if (count >= MAX_CONTACTS) break;

		if (!ab_ensureCapacity(count + 1)) {
			puts("불러오기 중 메모리 부족.");
			break;
		}

		// 내용 복사 후 내용의 길이가 이름길이보다 길게 쓰면 정리
		strncpy(contacts[count].name, name, NAME_LEN);
		contacts[count].name[NAME_LEN - 1] = '\0';

		strncpy(contacts[count].phone, phone, PHONE_LEN);
		contacts[count].phone[PHONE_LEN - 1] = '\0';

		strncpy(contacts[count].addr, addr, ADDR_LEN);
		contacts[count].addr[ADDR_LEN - 1] = '\0';

		strncpy(contacts[count].email, email, EMAIL_LEN);
		contacts[count].email[EMAIL_LEN - 1] = '\0';

		strncpy(contacts[count].memo, memo, MEMO_LEN);
		contacts[count].memo[MEMO_LEN - 1] = '\0';

		count++;
	}

	fclose(fp);
	puts("연락처 불러오기 완료하였습니다.");

	return 1;
}

// | 문자 있는지 확인하는 함수
static int containsPipe(const char* s) {
	return (strchr(s, '|') != NULL); // strchr : 발견된 | 이후의 문자열을 return
}

// 전화번호 중복 확인 함수
static int findByPhone(const char* phone) {
	for (int i = 0; i < count; i++) {
		if (strcmp(contacts[i].phone, phone) == 0) {
			return i;	// 중복 있음
		}
	}

	return -1;	// 중복 없음
}

// 이름으로 정렬 함수 - qsort() 함수 사용하여 정렬하기 - stdlib.h 에 포함
void sortByName() {
	if (count <= 1) {
		puts("정렬 불필요합니다.");
		return;
	}

	// quick-sort
	qsort(contacts, count, sizeof(Contact), cmpContactName);
	puts("이름순 정렬 완료.");
}

// 이름 비교 함수
static int cmpContactName(const void* a, const void* b) {
	const Contact* ca = (const Contact*)a;
	const Contact* cb = (const Contact*)b;

	return strcmp(ca->name, (*cb).name);
}

// 주소록 초기화 함수
int ab_init() {
	capacity = INIT_CAPACITY;
	count = 0;

	// 메모리 동적 할당
	contacts = (Contact*)malloc(sizeof(Contact) * capacity);
	if (!contacts) {
		puts("메모리 할당 실패.");
		return 0;
	}

	return 1;
}

// 주소록 메모리 해제 함수
void ab_free() {
	free(contacts);
	contacts = NULL;	// NULL로 할당하여 완전 제거
	count = 0;
	capacity = 0;
}

// 주소록 크기가 작으면 동적으로 늘리는 함수
static int ab_ensureCapacity(int need) {
	Contact* newbuf;
	int newcap;

	if (need <= capacity) return 1;

	newcap = capacity;
	while (newcap < need) {
		// 기존 용량의 2배로 늘리기
		newcap *= 2;
	}

	newbuf = (Contact*)realloc(contacts, sizeof(Contact) * newcap);
	if (!newbuf) {
		puts("메모리 재할당 실패(메모리 부족)");
		return 0;
	}

	contacts = newbuf;
	capacity = newcap;

	return 1;
}

#pragma endregion
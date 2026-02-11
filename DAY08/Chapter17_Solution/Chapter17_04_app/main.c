// Chapter17_04_app/main.c
// 구조체 포인터 -> 연산자

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Score {
	int kor;		// 국어점수
	int eng;		// 영어점수
	int math;		// 수학점수
};

struct Address {
	char name[20];	// 이름
	int age;		// 나이
	char tel[20];	// 전화번호
	char addr[80];	// 주소
};

// 구조체 배열을 주소로 받아서 출력하는 함수 선언
void print_List(struct Address*);

int main() {
	// struct Score yuni = { 90,80,70 };	// 일반적인 방법
	struct Score yuni = {					// 정확하게 초기화하는 방법
		.kor = 90,
		.eng = 80,
		.math = 70
	};	
	struct Score* ps = &yuni;				// 구조체 포인터에 주소를 저장

	// (*ps). 연산이 복잡함.
	// 이를 단순화 시키는 것이 '->'
	// 아래 "국어" 관련 줄 내용은 출력 결과가 동일한 내용이다.
	// printf("국어 : %d\n", (*ps).kor);
	printf("국어 : %d\n", ps->kor);
	printf("영어 : %d\n", ps->eng);
	printf("수학 : %d\n", ps->math);

	// 구조체 배열
	struct Address addrList[5] = {
		{ "홍길동" , 23, "111-1111", "울릉도 독도"},
		{ "이순신" , 35, "222-2222", "서울 건천동"},
		{ "장보고" , 19, "333-3333", "완도 청해진"},
		{ "유관순" , 15, "444-4444", "충남 천안"},
		{ "안중근" , 45, "555-5555", "황해도 해주"},
	};

	// 출력을 main() 함수에서 하면 쉬움.
	printf("main() 에서 출력\n");
	for (int i = 0; i < 5; i++) {
		printf("%10s%5d%15s%20s\n", addrList[i].name, addrList[i].age, addrList[i].tel, addrList[i].addr);
	}

	printf("print_List() 에서 출력\n");
	print_List(addrList);

	return 0;
}

// 구조체 배열 포인터를 사용하면
// *(포인터) 연산자로 작업하면 연산이 복잡해짐
// 그래서, 대신 '->' 를 사용하는 것
void print_List(struct Address* lp) {
	int i = 0;
	for (i = 0; i < 5; i++) {
		printf("%10s%5d%15s%20s\n", (lp+i)->name, (lp + i)->age, (lp + i)->tel, (lp + i)->addr);
	}
}
// Chapter17_05_app/main.c
// 공용체 ( Union )
// 구조체와 유사함.
// 다른 점은 하나의 저장공간을 같이 사용하는 것.
// 메모리 용량을 완전 최적화(절약) 할 때 사용
// 단, 멤버 변수끼리 데이터 충돌이 발생할 수 있음.

// 열거형 ( enumeration ) 
// 변수에 저장하는 정수 값을 기호로 대체, 나열
// 멤버 변수를 대문자와 _로 보통 사용

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// union 정의
union Student {
	int num;		// 학번
	double grade;	// 학점
};

// enum 정의
enum Season { SPRING = 1, SUMMER = 3, FALL, WINTER = 8 };


int main() {

	union Student st1 = {
		.num = 315,
	};

	// 공용체 Student 는 8byte의 크기를 가지고 있음.
	printf("공용체 크기 : %zu\n", sizeof(st1));
	printf("학번 : %d\n", st1.num);

	st1.grade = 4.4;
	printf("학점 : %.1f\n", st1.grade);
	//printf("학번 : %d\n", st1.num);

	// 열거형 사용
	enum Season ss;		// 열거형 변수 선언
	char* pc = NULL;

	ss = SPRING;

	switch (ss) {
		case SPRING : 
			pc = "inline";
			break;
		case SUMMER:
			pc = "swimming";
			break;
		case  FALL :
			pc = "tracking";
			break;
		case WINTER : 
			pc = "skiing";
			break;
	}

	printf("SEASON : %s\n", pc);

	return 0;
}
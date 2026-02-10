// Chapter17_01_app/main.c
// 구조체

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 구조체 선언
struct student {
	int number;			// 구조체 멤버, 학번
	double grade;		// 구조체 멤버, 학점
};

int main() {
	
	struct student st1;	// 구조체 student형 변수로 선언
	st1.number = 2;
	st1.grade = 4.5;

	printf("학번 : %d\n", st1.number);
	printf("학점 : %.1f\n", st1.grade);

	

	return 0;
}
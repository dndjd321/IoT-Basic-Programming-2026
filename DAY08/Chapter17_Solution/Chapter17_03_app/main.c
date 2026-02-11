// Chapter17_03_app/main.c

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Profile		// 프로필 구조체 정의
{
	int age;		// 나이
	double height;	// 키
};

struct Student		// 학생 구조체 정의
{
	int id;			// 학번
	double grade;	// 학점
	struct Profile profile;	// 프로필 
};

int main() {
	// C99 표준이상 사용하는 구조체 선언과 동시 초기화 방법
	struct Student stu1 = {
		.id = 9537,
		.grade = 4.1,
		.profile = {
			.age = 25,
			.height = 173.0
		}
	};

	stu1.id = 9537;
	stu1.grade = 4.1;

	stu1.profile.age = 25;
	stu1.profile.height = 173.0;

	// 출력
	printf("학번 : %d\n", stu1.id);
	printf("학점 : %.1f\n", stu1.grade);
	printf("나이 : %d\n", stu1.profile.age);
	printf("키 : %.1f\n", stu1.profile.height);

	return 0;
}
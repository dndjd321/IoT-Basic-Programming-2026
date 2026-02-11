// Chapter17_06_app/main.c
// 구조체, 공용체 재정의

#include <stdio.h>

struct Student {
	int num;
	double grade;
};

// type 재정의. 
// Student를 stu로 재정의. stu로 호출 가능.
typedef struct Student stu;

void PrintData(stu*);

int main() {
	stu st1;	// struct Student st1; 과 동일

	st1.num = 2;
	st1.grade = 4.3;

	PrintData(&st1);

	return 0;
}

void PrintData(stu* ps) {
	printf("학번 : %d\n", ps->num);
	printf("학점 : %.1f\n", ps->grade);
}
// Chapter14_01_app/main.c
// 다차원 배열과 포인터 배열

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	//2차원 배열로 성적 처리
	//int score[3][4];	// 4byte * 3 * 4 = 48bytes
	//int score[3][4] = { 0 };
	int score[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};

	int total;
	double avg;



	int i, j;			// 2중 for문 변수
	for (i = 0; i < 3; i++) {
		//printf("%d번 학생, 4과목 점수 입력\n", i + 1);
		for (j = 0; j < 4; j++) {
			if (j == 0) printf("국어 : ");
			else if (j == 1) printf("수학 : ");
			else if (j == 2) printf("영어 : ");
			else if (j == 3) printf("과학 : ");

			//scanf("%d", &score[i][j]);
		}
	}

	// 점수 채점
	for (i = 0; i < 3; i++) {
		total = 0;

		for (j = 0; j < 4; j++) {
			total += score[i][j];
		}

		avg = total / 4.0;

		//printf("%d번 학생, 총점 : %d, 평균 : %.2f\n", i + 1, total, avg);
	}

	printf("\n");


	//2차원 배열로 동물 이름 관리
	char animal[5][20];	// 동물 5마리, 이름 길이 20
	int count;

	// sizeof(animal) == 100 , sizeof(animal[0]) == 20
	count = sizeof(animal) / sizeof(animal[0]);
	//printf("%d", count);

	for (i = 0; i < count; i++) {
		scanf("%s", animal[i]);
	}

	for (i = 0; i < count; i++) {
		printf("%d번 동물 %s", i, animal[i]);
	}

	printf("\n");


	return 0;
}
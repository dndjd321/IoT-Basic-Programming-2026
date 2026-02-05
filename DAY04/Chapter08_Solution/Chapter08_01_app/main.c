// Chapter08_01_app/main.c
// 배열

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	//int kor, math, eng, social, science;

	//int arr[5];	// 1. 배열 선언	// 크기 5인 정수형 배열 선언
	//int arr[5] = { 90,85,70,95,100 };	// 2. 배열 선언과 동시에 초기화
	int arr[5] = { 0 };	// 3. 배열 선언과 동시에 0으로 초기화
	int arr2[] = { 0,1,2,4 };	// 4. 배열 초기화로 배열 크기 자동 결정

	int tot = 0;
	double avg = 0.0;	// 평균점수

	arr[0] = 90;
	arr[1] = 85;
	arr[2] = 70;
	arr[3] = 95;
	arr[4] = 100;

	printf("국어 점수: %d\n", arr[0]);
	printf("수학 점수: %d\n", arr[1]);
	printf("영어 점수: %d\n", arr[2]);
	printf("사회 점수: %d\n", arr[3]);
	printf("과학 점수: %d\n", arr[4]);

	// 합산
	//tot = arr[0] + arr[1] + arr[2] + arr[3] + arr[4];
	for (int i = 0; i < 5; i++) {
		tot += arr[i];
	}

	avg = tot / 5.0;

	printf("총점: %d\n", tot);
	printf("평점: %.1f\n", avg);

	return 0;
}
// Chapter16_03_app/main.c
// 나머지 동적할당 함수

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int* pi = NULL;
	int size = 5;
	int count = 0;
	int number, i = 0;

	// calloc() : contigous allocation ( 연속된 메모리 할당 ) 
	pi = (int*)calloc(size, sizeof(int));	// 20byte 저장공간 
	// pi = (int*)malloc(size * sizeof(int)); 와 동일

	while (1) {
		printf("양수만 입력하세요 => ");
		scanf("%d", &number);

		if (number <= 0) {
			break;	// 양수 입력 중지
		}

		if (count  == size) {	// size 초기상태(5)의 크기를 다 사용했다면
			size += 5;			// size 크기 + 5

			// pi ( 20byte ) 를 늘린 size의 크기 ( 10 ) * 4 => pi ( 40 byte )로 증가시키기
			// 새로 늘어난 공간은 가비지 값으로 초기화
			// realloc : re-allocation ( 메모리 재할당 )
			pi = (int*)realloc(pi, size * sizeof(int));
		}

		pi[count++] = number;

	}

	for (i = 0; i < count; i++) {
		printf("%5d", pi[i]);
	}

	free(pi);	// 메모리 동적 할당한 공간(메모리)을 OS에 반환

	return 0;
}
// Chapter16_02_app/main.c
// 동적으로 배열크기 할당

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int* pi = NULL;
	int i = 0, sum = 0;

	pi = (int*)malloc(5 * sizeof(int));	// 20byte 할당
	if (pi == NULL) {
		printf("### pi >>> 메모리가 할당되지 않았습니다.\n");
		exit(1);
	}

	printf("5명의 나이를 입력하세요. : ");
	for (i = 0; i < 5; i++) {
		scanf("%d", &pi[i]);
		sum += pi[i];
	}

	printf("5명의 평균 나이 : %.1f\n", sum / 5.0);
	
	free(pi);

	return 0;
}
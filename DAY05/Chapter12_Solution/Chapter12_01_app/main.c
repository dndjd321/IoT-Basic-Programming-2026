// Chapter12_01_app/main.c
// 문자열

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	// 문자열 출력
	printf("%s\n", "apple");

	// 문자열 주소 확인
	printf("apple 문자열의 시작 주소 %u\n", "apple");
	printf("두번째 문자 주소 %u\n", "apple" + 1);
	printf("두번째 문자 %c\n", *("apple" + 1));
	printf("첫번째 문자 %c\n", *("apple"));
	printf("첫번째 문자 %c\n", "apple"[0]);

	char fruit[6] = "apple";
	printf("fruit 문자 배열의 시작 주소 %u\n", fruit);
	printf("두번째 문자 주소 %u\n", fruit + 1);
	printf("두번째 문자 %c\n", *(fruit + 1));
	printf("첫번째 문자 %c\n", *(fruit));
	printf("첫번째 문자 %c\n", fruit[0]);

	//fruit = "banan";	// 문자 배열의 값을 직접 할당하는 방식으로 변경할 수는 없음.
	strcpy(fruit, "banan");
	printf("%s\n", fruit);

	char* dessert = "apple";	// 하지만 포인터 변수는 값을 직접 할당하는 방식으로 변경하는 것이 가능함.
	printf("%s\n", dessert);
	dessert = "banan";
	printf("%s\n", dessert);

	return 0;
}
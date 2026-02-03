//Chapter03_02_app/main.c
// 실수형

#define _CRT_SECURE_NO_WARNINGS	// 보안 문제 이전의 오래된 함수사용을 위해서
#include <stdio.h>	// 표준 입출력 헤더 파일
#include <float.h>	// 실수형 타입의 최소, 최대값을 담고 있는 헤더 파일
#include <string.h>	// 문자열 처리를 위한 라이브러리

int	main(void) {
	// float : 4bytes
	// double(기본) : 8bytes
	printf("변수 float, %zu byte, 최소 %e, 최대 %e\n", sizeof(float), FLT_MIN, FLT_MAX);
	printf("변수 double, %zu byte, 최소 %e, 최대 %e\n", sizeof(double), DBL_MIN, DBL_MAX);

	// 문자열 : 문자의 배열(char Array)
	char fruit[20] = "strawberry";
	printf("과일 이름 : %s\n", fruit);

	// fruit = "banana"; 문자열에서 대입은 불가
	// 대신 아래와 같이 함수를 사용해서 변수값을 변경
	strcpy(fruit, "banana");
	printf("변경된 과일 이름 : %s\n", fruit);

	// const : 변하지 않는 값을 지정
	const double tax_rate = 0.10;	// 세율
	const double pi = 3.141592;		// 원주율
	int income = 5000;
	double tax = income * tax_rate;

	printf("세금은 : %.0f원\n", tax);

	//tax_rate = 0.20;	// const는 이후에 변경 불가


	int age;	// unsigned char(최대값 255) 가 가장 적합
	/*
		-변수명 지정방식-
		알파벳 A-Z, a-z, 0~9, '_' 까지만 허용
		숫자로 시작할 수 없음
		대소문자 구별
		예약어는 변수명으로 사용 불가

		의미있는 단어들의 조합으로 변수명을 선언할 것
	*/

	char full_name[50] = "asd";
	int age = 50;
	char address[100] = "부산";
	char blood_type = 'A';
	float height = 100.9f;




	return 0;
}




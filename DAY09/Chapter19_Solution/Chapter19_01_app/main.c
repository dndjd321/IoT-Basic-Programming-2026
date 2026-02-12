// Chapter19_01_app/main.c
// 헤더 파일 사용


// 매크로 정의
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265359
#define LIMIT 100.0
#define MSG "passed."
#define ERR_PRN printf("허용범위 초과.");

// 조건부 컴파일 지시자
#define VER 6
#define BIT16

#include <stdio.h>				// 빌트 인 라이브러리(헤더파일)은 "<" 꺽새로 선언
#include "./include/student.h"	// 사용자가 만든 라이브러리는 '"' 쌍따옴표로 선언

void func();

int main() {
	Stu st1 = { 315, "홍길동" };
	double radius, area;	// 반지름, 면적


	int max;

#ifndef BIT16
	// 컴파일할 내용 추가
#endif // !BIT16


#if VER >= 6
	printf("버전 %d입니다.\n", VER);
#else
#error 컴파일러 버전은 6.0 이상이어야 합니다.
	//printf("버전 확인하십시오.\n");
#endif

#ifdef BIT16
	max = 32767;
#else
	max = 2417483647;
#endif 



	printf("학번은 %d, 이름은 %s\n", st1.num, st1.name);

	radius = 5;
	area = radius * radius * PI;
	if (area > LIMIT) {	// 계산된 면적이 100.0을 넘으면
		ERR_PRN;		// 새로 정의한 ERR_PRN 호출하여 printf("허용범위 초과.") 출력
	}
	else {
		printf("원 면적 : %.2lf (%s)\n", area, MSG);
	}

	printf("컴파일(빌드) 날짜와 시간 : %s, %s\n", __DATE__, __TIME__);
	printf("파일명 : %s\n", __FILE__);
	printf("함수명 : %s\n", __FUNCTION__);
	printf("행번호 : %d\n", __LINE__);
	
#line 100 "macro.c"	// 행번호를 100으로 변경 및 파일명도 macro.c 로 표시
	func();

	return 0;
}

void func() {
	printf("\n");
	printf("파일명 : %s\n", __FILE__);
	printf("함수명 : %s\n", __FUNCTION__);
	printf("행번호 : %d\n", __LINE__);
}
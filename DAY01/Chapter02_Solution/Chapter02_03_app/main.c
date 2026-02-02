// Chapter02_03_app > main.c
// 진법 표시

#include <stdio.h>
#include <limits.h>			// 각 타입별 최대/최소값이 정의된 헤더 파일

int main() {
	printf("int의 최소값 : %d\n", INT_MIN);
	printf("int의 최대값 : %d\n", INT_MAX);

	printf("%d\n", 12);		// 10진수 12
	printf("%d\n", 014);	// 8진수 14 -> 10진수 12
							// 0으로 시작하는 숫자는 8진수로 인식
	printf("%d\n", 0xC);	// 16진수 C -> 10진수 12
							// 0x로 시작하는 숫자는 16진수로 인식


	printf("%d\n", 12);		// 10진수
	printf("%o\n", 12);		// 12를 8진수로 출력
	printf("%x\n", 12);		// 12를 16진수로 출력(소문자)
	printf("%X\n", 12);		// 12를 16진수로 출력(대문자)

	// 지수표현
	printf("%.1lf\n", 1e6);
	printf("%.7lf\n", 3.14e-5);

	// 문자, 문자열
	// C 에서는 문자 != 문자열
	printf("%c\n", 'A');	// 문자 출력
	printf("%s\n", "A");	// 문자열 출력
	printf("%d\n", 'A');	// 아스키 코드 65 출력
	
	// 문자는 무조건 변환문자 %c 로 출력
	// 문자열은 무조건 변환문자 %s 로 출력
	// 혼용 불가
	printf("%c는 %s입니다.\n", '1', "First");	



	return 0;
}



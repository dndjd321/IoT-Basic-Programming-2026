// Chapter03_01_app/main.c
// 변수

#include <stdio.h>	// 표준 입출력 헤더 파일
#include <limits.h>	// 타입의 최소, 최대값을 담고 있는 헤더 파일

int main() {
	// 변수 선언
	int a;				// 정수형 변수 a 선언
	int b, c;			// 정수형 변수 b, c 선언
	float f;			// 실수형 변수 f 선언
	double d;			// 더 정밀한 실수형 변수 d 선언
	char ch;			// 문자형 변수 ch 선언
	
	// assignments(대입) 왼쪽의 변수에 오른쪽에는 값을 넣음.
	// 변수에 값 할당
	a = 10;				// 변수 a에 10 할당
	b = a;				// 변수 b에 20 할당
	c = a + 20;			// 변수 c에 a와 b의 합 할당
	//c = 3.145;		// Ctrl + / : 주석 처리
	f = 3.14159f;		// 변수 f에 3.14 할당
	d = 3.1415926535;	// 변수 d에 3.1415926535 할당
	ch = 'A';			// 변수 ch에 문자 'A' 할당

	// 변수 값 출력
	printf("변수 a = %d\n", a);		// 변수 a 출력
	printf("변수 b = %d\n", b);		// 변수 b 출력
	printf("변수 c = %d\n", c);		// 변수 c 출력
	
	// '%f'는 소수점 6자리까지 출력, '%.nf'는 소수점 n자리까지 출력
	printf("변수 f = %f\n", f);		// 변수 f 출력
	printf("변수 d = %.10f\n", d);	// 변수 d 출력

	// '%c'는 문자 하나를 출력, '%s'는 문자열 출력
	printf("변수 ch = %c\n", ch);	// 변수 ch 출력
	printf("변수 ch = %d\n", ch);	// 변수 ch 출력 ( 아스키 코드 값으로 출력 )

	// ASCII - 영문자, 특수문자(+,-,etc.) 등 숫자값으로 1:1 매칭되어 있음.
	// https://ko.wikipedia.org/wiki/ASCII - ASCII 코드 표
	printf("변수 ch = %c\n", 66);	// 'B' 출력
	printf("변수 ch = %c\n", 97);	// 'a' 출력

	// 정수형
	// char : 크키 1 byte -> 8bit 0000 0000 ~ 1111 1111 -> 00 ~ FF(0~255 까지 표현)
	// short : 크기 2 bytes
	// int(기본) : 크기 4 bytes
	// long : 크기 4 bytes
	// long long : 크기 8 bytes
	printf("변수 char의 사이즈 : %zu byte, 최소 %d, 최대 %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
	printf("변수 short의 사이즈 : %zu byte, 최소 %d, 최대 %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
	printf("변수 int의 사이즈 : %zu byte, 최소 %d, 최대 %d\n", sizeof(int), INT_MIN, INT_MAX);
	printf("변수 long long의 사이즈 : %zu byte, 최소 %lld, 최대 %lld\n", sizeof(long long), LLONG_MIN, LLONG_MAX);

	// unsigned : 음수 표현 없이 양수와 0만 표현
	printf("변수 unsigned char의 사이즈 : %zu byte, 최소 %d, 최대 %d\n", sizeof(unsigned char), 0, UCHAR_MAX);
	printf("변수 unsigned short의 사이즈 : %zu byte, 최소 %d, 최대 %d\n", sizeof(unsigned short), 0, USHRT_MAX);
	printf("변수 unsigned int의 사이즈 : %zu byte, 최소 %d, 최대 %u\n", sizeof(unsigned int), 0, UINT_MAX);
	printf("변수 unsigned long의 사이즈 : %zu byte, 최소 %d, 최대 %u\n", sizeof(unsigned long), 0, ULONG_MAX);
	printf("변수 unsigned long long의 사이즈 : %zu byte, 최소 %d, 최대 %llu\n", sizeof(unsigned long long), 0, ULLONG_MAX);

	return 0;			// 프로그램 종료
}
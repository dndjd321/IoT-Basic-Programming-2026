// Chapter04_01_app/main.c
// 연산자

#define _CRT_SECURE_NO_WARNINGS	// for Visual Studio에서 안전하지 않은 함수 사용 경고 제거
#include <stdio.h>

int main() {
	// 산술 연산자
	int x, y;
	int sum, sub, mul, mod;
	double div;
	int inv;

	x = 7;
	y = 3;

	sum = x + y;			// 덧셈
	sub = x - y;			// 뺄셈
	mul = x * y;			// 곱셈
	div = (double)x / y;	// 나눗셈
	mod = x % y;			// 나머지
	inv = -x;

	printf("x = %d, y = %d:\n", x, y);
	printf("x + y = %d\n", sum);
	printf("x - y = %d\n", sub);
	printf("x × y = %d\n", mul);
	printf("x ÷ y = %.2f\n", div);
	printf("x ％ y = %d\n", mod);

	printf("inverse x = %d\n", inv);

	// = 대입 연산자
	int a = 10;				// int형 변수 a에 10을 할당.
	int b = 20;

	// ++, -- 증감 연산자
	// 증감 연산자의 위치에 따라 처리되는 순서가 다름.
	++a;
	a++;
	--b;
	b--;
	
	printf("a = %d\n", a);
	printf("b = %d\n", b);

	// 관계 연산자
	int d = 10;
	int res;		// 결과 저장 변수

	// false == 0, true == 1
	res = (a > b);	// false
	printf("a > b : %s\n", res ? "true" : "false");
	printf("a >= b : %s\n", a >= b ? "true" : "false");

	res = (a < b);
	printf("a < b : %s\n", res ? "true" : "false");
	printf("a <= b : %s\n", a <= b ? "true" : "false");

	// ==, != 동치비교 연산자
	res = (a == b);	
	res = (a != b);

	a = 10;
	b = 20;

	// &&(AND), ||(OR), !(NOT) 논리 연산자 
	res = (a > 10) && (b < 20);		// false
	printf("(a > 10) && (b < 20) : %d\n", res);
	res = (a <= 10) && (b > 10);	// true
	printf("(a <= 10) && (b > 10) : %d\n", res);
	res = (a < 10) || (b > 10);
	printf("(a < 10) || (b > 10) : %d\n", res);
	res = !(a >= 30);
	printf("!(a >= 30) : %d\n", res);

	// 형 변환 연산자
	// int, short, char, long, long long, float, double...
	printf("%d\n", (int)3.141592);
	printf("%f\n", (float)3);
	// 형 변환 방식 : (데이터형)
	
	// 자동형변환
	char chVal = 65;
	int iVal = 0;
	iVal = chVal;
	printf("%d\n", iVal);

	// sizeof 연산자
	int g = 25;
	float h = 3.1f;
	char ch = 'A';

	printf("int형의 변수 크기 : %lld\n", sizeof(g));
	printf("int형 크기 : %lld\n", sizeof(int));
	printf("float형 크기 : %lld\n", sizeof(h));
	printf("double형 크기 : %lld\n", sizeof(1.5 + 3.4));
	printf("char형 크기 : %lld\n", sizeof(ch));		// 'A'를 바로 대입하면 ASCII 코드 Value 값인
													// 65로 들어가서 int형으로 인식함

	// 복합대입 연산자
	a += 5;		// a = a + 5
	// -=, *=, /=, %=

	res = 2;
	a = 10, b = 20;
	int c = 30;
	res *= b + 10;
	printf("%d\n", res);

	// 콤마 연산자
	// 한 번에 여러개의 수식을 차례로 나열해야 할 때 사용
	res = (++a, ++b);	// a도 1증가, b도 1증가 후, 가장 오른쪽에 있는 피연산자값을 res에 대입
	printf("%d, %d, %d\n", a, b, res);
	
	res = (++a, ++b, ++c);
	printf("%d, %d, %d ,%d\n", a, b, c, res);

	// 삼항 연산자
	// 조건 식 ? true일 때 결과 값 : false일 때 결과 값

	int i = 30, j = 25;
	printf("작은 값 : %d\n", (i < j) ? i : j);


	// 비트 연산자, 2진수 변환 후 0은 false, 1은 true로 감안
	a = 10;		// 2진수 00000000 00000000 00000000 00001010 == (int)10
	b = 12;		// 2진수 00000000 00000000 00000000 00001100 == (int)12
	
	// &(and), |(or), ^(xor), ~(not), << >>(shift)
	printf("a & b : %d\n", (a & b));	// 00000000 00000000 00000000 00001000 == (int)8
	printf("a | b : %d\n", (a | b));	// 00000000 00000000 00000000 00001110 == (int)14

	return 0;
}
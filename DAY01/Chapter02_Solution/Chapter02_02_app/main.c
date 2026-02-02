// Chapter02_02_app > main.c
// 탈출 문자(\ Escape Character), 변환문자(%) 학습

#include <stdio.h>

int main(void) {
	// 콘솔에 문자열을 format에 맞춰서 출력하는 함수
	printf("Hello, World!\n");

	// escape character
	// '\n' : New Line - 줄 바꿈 
	printf("12345\n");
	printf("67890\n");
	printf("WOW\n");
	
	// '\t' : Tab - 큰 여백
	printf("My friend, Puka.\n");
	printf("My\tfriend,\tPuka.\n");

	// '\b' : BackSpace - \b 앞 글자 지우기
	printf("Goot\bd Morning.\n");

	// '\a' : Alram - 시스템 소리 출력
	printf("Bark!\a\n");

	// '\r' : Carriage Return - \r 뒤에 있는 글자를 맨 앞으로 가서 덮어쓰기
	printf("Department\rLotte\n");

	// 숫자를 Console에 출력하는 기능
	// '%d' : Decimal => 정수를 문자로 출력
	// '%nd' : n Decimal => n의 자리수만큼 늘려서 출력
	printf("%d\n", 10);
	printf("%10d\n", 10);

	// '%f' : Float => 실수를 문자로 출력
	// '%lf' : Long Float => 소수점을 6자리까지 문자로 출력
	printf("%f\n", 3.141592);
	printf("%lf\n", 3.14);

	// '%.nf' : n Float => 소수점을 n자리까지 문자로 출력
	printf("%.2f\n", 3.14159265727);

	// 여러개의 파라미터
	printf("%5d*%5d=%5d\n", 6, 7, 6*7);

	return 0;
}



// Chapter05_07_app/main.c
// Infinity Loop Example is C

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	int i = 1;

	// while loop for infinity
	/*while (1) 
	{
		printf("IF %d\n", i);
		i++;
	}*/

	// for loop for infinity
	/*for(;;){
		printf("IF %d\n", i);
		i++;
	}*/

	while (1) {
		printf("Be Happy.\n");
		i++;
		if (i == 10) { break; }
	}


	// continue : 특정 상황에서 일부 반복을 제외시킬 때 사용
	for (i = 1; i <= 100; i++) 
	{
		if (i % 3 == 0) {	// 3의 배수일 때는, 반복문 아래를 실행하지 않고 다음 반복으로 넘어감.
			continue;
		}
		printf("%d\t", i);
	}

	printf("\n");

	

	
	return 0;
}
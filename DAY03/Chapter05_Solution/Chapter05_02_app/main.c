// Chapter05_02_app/main.c
// switch ~ case 문

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	int rank = 0, money = 0;	// 변수 선언 및 초기화

	printf("등수를 입력하세요 : ");
	scanf("%d", &rank);
	
	//switch (rank) {
	//	case 1:
	//		money = 1000;
	//		break;	// break 문을 만나면 switch 문을 빠져나감.
	//				// break 문이 없으면 다음 case 문으로 계속 진행됨.
	//	case 2:
	//		money = 500;
	//		break;
	//	case 3:
	//		money = 200;
	//		break;
	//	case 4:
	//		money = 50;
	//		break;
	//	default:
	//		money = 10;
	//		break;
	//}
	
	if (rank == 1) money = 1000;
	else if (rank == 2) money = 500;
	else if (rank == 3) money = 200;
	else if (rank == 4) money = 50;
	else money = 10;

	printf("%d등 당첨금은 %d만원 입니다.\n", rank, money);

	return 0;
}


// Chapter05_02_app/main.c
// switch ~ case 구문

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	int rank = 0, money = 0;	// 랭크, 당첨금

	printf("순위를 입력하세요 :  ");
	scanf("%d", &rank);
	
	//switch (rank) {
	//	case 1:
	//		money = 1000;
	//		break;	// break 문은 필수
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

	printf("%d 등 당첨금은 %d 만원 입니다.\n", rank, money);

	return 0;
}


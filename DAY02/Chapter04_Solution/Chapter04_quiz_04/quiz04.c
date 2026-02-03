// Chapter04_quiz_02/quiz02.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	double w = 0;
	double h = 0;
	double bmi = 0.0;

	printf("몸무게(kg)와 키(cm) 입력 : ");
	scanf("%lf %lf", &w, &h);
	bmi = w / ((h / 100) * (h / 100));

	if(bmi >= 20 && bmi <25) {
		printf("bmi : %.6f, 표준입니다.\n", bmi);
	}
	else {
		printf("bmi : %.6f, 체중관리가 필요합니다.\n", bmi);
	}

	return 0;
}
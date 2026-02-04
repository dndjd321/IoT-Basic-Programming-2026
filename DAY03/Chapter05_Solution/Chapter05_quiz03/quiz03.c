// 별 찍기



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	/*
		*****
		*****
		*****
		*****
		*****
	*/
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n");


	/*
		*
		**
		***
		****
		*****
	*/
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n");


	/*
			*
		   **
		  ***
		 ****
		*****
	*/
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5 - i; j++) {
			printf(" ");
		}
		for (int k = 1; k <= i; k++) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n");

	/*
			*
		   ***
		  *****
		 *******
		*********
	*/
	for (int i = 1; i < 10; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= (9 - i) / 2; j++) {
				printf(" ");
			}
			for (int k = 1; k <= i; k++) {
				printf("*");
			}
			printf("\n");
		}
	}

	printf("\n");

	/*
		*********
		 *******
		  *****
		   ***
		    *
	*/
	for (int i = 9; i > 0; i--) {
		if (i % 2 == 1) {
			for (int j = 1; j <= (9 - i) / 2; j++) {
				printf(" ");
			}
			for (int k = 1; k <= i; k++) {
				printf("*");
			}

			printf("\n");
		}
	}

	printf("\n");

	/*
	    *********
		 *******
		  *****
		   ***
			*
		   ***
		  *****
		 *******
		*********
	*/

	for (int i = 9; i > 0; i--) {
		if (i % 2 == 1) {
			for (int j = 1; j <= (9 - i) / 2; j++) {
				printf(" ");
			}
			for (int k = 1; k <= i; k++) {
				printf("*");
			}

			printf("\n");
		}
	}
	for (int i = 3; i < 10; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= (9 - i) / 2; j++) {
				printf(" ");
			}
			for (int k = 1; k <= i; k++) {
				printf("*");
			}
			printf("\n");
		}
	}

	printf("\n");


	/*
			*
		   ***
		  *****
		 *******
		*********
		 *******
		  *****
		   ***
			*
	*/
	for (int i = 1; i < 10; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= (9 - i) / 2; j++) {
				printf(" ");
			}
			for (int k = 1; k <= i; k++) {
				printf("*");
			}
			printf("\n");
		}
	}
	for (int i = 7; i > 0; i--) {
		if (i % 2 == 1) {
			for (int j = 1; j <= (9 - i) / 2; j++) {
				printf(" ");
			}
			for (int k = 1; k <= i; k++) {
				printf("*");
			}

			printf("\n");
		}
	}

	printf("\n");

	/*
		*   *
		 * *
		  *
		 * *
		*   *
	*/
	for (int i = 1; i <= 5; i++) {
		if (i % 2 == 1) {
			if (i != 3) {
				for (int j = 1; j <= 5; j++) {
					if(j != 1 && j!=5) printf(" ");
					else printf("*");
				}
				printf("\n");
			}
			else {
				for (int j = 1; j <= 5; j++) {
					if (j != 3) printf(" ");
					else printf("*");
				}
				printf("\n");
			}
		}
		else {
			for (int j = 1; j <= 5; j++) {
				if (j % 2 != 0 ) printf(" ");
				else printf("*");
			}
			printf("\n");
		}
	}


	return 0;
}
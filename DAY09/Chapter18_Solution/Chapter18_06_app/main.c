// Chapter18_06_app/main.c
// 텍스트 파일, 바이너리파일 비교

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

int main() {
	FILE* tfp, *bfp;	// tfp = text, bfp = binary

	int num = 97;
	int res;

	tfp = fopen("./text.txt", "wt");
	fprintf(tfp, "%d", num);

	bfp = fopen("./binary.dat", "wb");
	// 배열일 경우
	// fwrite(arr, sizeof(arr[0]), arr.length, bfp);
	fwrite(&num, sizeof(num), 1, bfp);

	fclose(tfp);
	fclose(bfp);

	bfp = fopen("./binary.dat", "rb");
	fread(&res, sizeof(res), 1, bfp);
	printf("%d\n", res);

	fclose(bfp);

	printf("처리 완료.\n");

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <iostream>

typedef struct {
	int phan_nguyen;  
	int tu_so;         
	int mau_so;        
} HonSo;

// Hàm tạo mảng hỗn số ngẫu nhiên
void tao_mang_hon_so(HonSo b[], int n) {
	srand((unsigned)time(NULL)); 

	for (int i = 0; i < n; ++i) {
		b[i].phan_nguyen = rand() % 100;   
		b[i].tu_so = rand() % 100;         
		do {
			b[i].mau_so = rand() % 100;   
		} while (b[i].mau_so == 0);
	}
}
int main() {
	int n = 5;  
	HonSo *mang_hs; 

	mang_hs = (HonSo *)malloc(n * sizeof(HonSo));

	if (mang_hs == NULL) {
		printf("Khong the cap phat bo nho!\n");
		return 1; 
	}

	tao_mang_hon_so(mang_hs, n);

	printf("Mang hon so vua tao:\n");
	for (int i = 0; i < n; ++i) {
		printf("%d   %d/%d\n", mang_hs[i].phan_nguyen, mang_hs[i].tu_so, mang_hs[i].mau_so);
	}

	free(mang_hs);
	system("pause");
	return 0;
}

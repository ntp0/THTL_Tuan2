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

// Hàm xuất danh sách hỗn số
void xuat_danh_sach_hon_so(HonSo *b, int n) {
	printf("Danh sach hon so:\n");
	for (int i = 0; i < n; ++i) {
		printf("%d\t%d/%d\n", b[i].phan_nguyen, b[i].tu_so, b[i].mau_so);
	}
}	

int main() {
	int n = 10;  
	HonSo *mang_hs; 

	mang_hs = (HonSo *)malloc(n * sizeof(HonSo));

	if (mang_hs == NULL) {
		printf("Khong the cap phat bo nho!\n");
		return 1; 
	}

	tao_mang_hon_so(mang_hs, n);

	xuat_danh_sach_hon_so(mang_hs, n);

	free(mang_hs);
	system("pause");
	return 0;
}

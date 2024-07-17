#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int phan_nguyen;  
	int tu_so;         
	int mau_so;         
} HonSo;

// Hàm tính giá trị thực của hỗn số
float gia_tri_thuc(HonSo hs) {
	return hs.phan_nguyen + (float)hs.tu_so / hs.mau_so;
}

// Hàm so sánh hai hỗn số
int so_sanh_hon_so(HonSo hs1, HonSo hs2) {
	float gt1 = gia_tri_thuc(hs1);
	float gt2 = gia_tri_thuc(hs2);

	if (gt1 > gt2) {
		return 1;
	}
	else if (gt1 < gt2) {
		return -1;
	}
	else {
		return 0;
	}
}

// Hàm tạo mảng hỗn số ngẫu nhiên
void tao_mang_hon_so(HonSo *b, int n) {
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
		printf("%d %d/%d\n", b[i].phan_nguyen, b[i].tu_so, b[i].mau_so);
	}
}

int main() {
	int n = 2;  
	HonSo *mang_hs;

	mang_hs = (HonSo *)malloc(n * sizeof(HonSo));

	if (mang_hs == NULL) {
		printf("Khong the cap phat bo nho!\n");
		return 1; 
	}

	tao_mang_hon_so(mang_hs, n);

	xuat_danh_sach_hon_so(mang_hs, n);

	// So sánh hai hỗn số trong mảng
	printf("\nSo sanh hai hon so trong mang:\n");
	int ket_qua = so_sanh_hon_so(mang_hs[0], mang_hs[1]);
	if (ket_qua == 1) {
		printf("Hon so thu nhat lon hon hon so thu hai.\n");
	}
	else if (ket_qua == -1) {
		printf("Hon so thu nhat nho hon hon so thu hai.\n");
	}
	else {
		printf("Hai hon so bang nhau.\n");
	}

	free(mang_hs);
	system("pause");
	return 0;
}

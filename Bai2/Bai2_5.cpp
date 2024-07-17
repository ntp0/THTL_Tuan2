#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int tu;   
	int mau; 
} PhanSo;

typedef struct {
	int nguyen; 
	PhanSo phanSo;  
} HonSo;

int randomNumber(int min, int max) {
	return min + rand() % (max - min + 1);
}

// Hàm tạo một phân số ngẫu nhiên
PhanSo taoPhanSoNgauNhien() {
	PhanSo ps;
	ps.tu = randomNumber(1, 9);   
	ps.mau = randomNumber(1, 9); 
	return ps;
}

// Hàm tạo một hỗn số ngẫu nhiên
HonSo taoHonSoNgauNhien() {
	HonSo hs;
	hs.nguyen = randomNumber(-10, 10);  
	hs.phanSo = taoPhanSoNgauNhien();   
	return hs;
}

// Hàm chuyển đổi hỗn số thành phân số
//PhanSo chuyenDoiHonSoThanhPhanSo(HonSo hs) {
//	PhanSo ps;
//	int tuMoi = hs.nguyen * hs.phanSo.mau + hs.phanSo.tu;
//	ps.tu = tuMoi;
//	ps.mau = hs.phanSo.mau;
//	return ps;
//}

// Hàm chuyển đổi từ phân số sang hỗn số
HonSo chuyenDoiPhanSoThanhHonSo(PhanSo ps) {
	HonSo hs;
	hs.nguyen = ps.tu / ps.mau;  // Phần nguyên của hỗn số
	hs.phanSo.tu = ps.tu % ps.mau;  // Tử số của phân số sau khi chia lấy dư
	hs.phanSo.mau = ps.mau;  // Mẫu số không thay đổi

	return hs;
}


//int main() {
//	srand(time(NULL));  
//	HonSo mangHonSo[10];  
//
//	printf("Cac hon so ngau nhien la:\n");
//	for (int i = 0; i < 2; ++i) {
//		mangHonSo[i] = taoHonSoNgauNhien();
//		printf("%d\t + %d/%d\n", mangHonSo[i].nguyen, mangHonSo[i].phanSo.tu, mangHonSo[i].phanSo.mau);
//	}
//
//	printf("\nChuyen doi cac hon so thanh phan so:\n");
//	for (int i = 0; i < 2; ++i) {
//		PhanSo ps = chuyenDoiHonSoThanhPhanSo(mangHonSo[i]);
//		printf("%d/%d\n", ps.tu, ps.mau);
//	}
//	system("pause");
//	return 0;
//}

int main() {
	// Khởi tạo một phân số
	PhanSo ps = { 5, 3 };  // Ví dụ phân số 5/3

	// Chuyển đổi phân số thành hỗn số
	HonSo hs = chuyenDoiPhanSoThanhHonSo(ps);

	// In kết quả
	printf("Phan so %d/%d duoc chuyen thanh hon so: %d + %d/%d\n", ps.tu, ps.mau, hs.nguyen, hs.phanSo.tu, hs.phanSo.mau);
	system("pause");
	return 0;
}
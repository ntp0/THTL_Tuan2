#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

//Hàm sắp xếp tăng dần
void interchangeSortAscending(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				swap(&arr[i], &arr[j]);
			}
		}
	}
}

// Hàm sắp xếp giảm dần
void interchangeSortDescending(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] < arr[j]) {
				swap(&arr[i], &arr[j]);
			}
		}
	}
}


const int MAX_SIZE = 100; 
int main() {
	int n;
	std::cout << "Nhap so luong phan tu cua mang (n <= " << MAX_SIZE << "): ";
	std::cin >> n;

	if (n > MAX_SIZE) {
		std::cout << "So luong phan tu vuot qua gioi han cho phep.\n";
		return 1;
	}

	int arr[MAX_SIZE]; 

	std::cout << "Nhap cac phan tu cua mang:\n";
	for (int i = 0; i < n; i++) {
		std::cout << "arr[" << i << "] = ";
		std::cin >> arr[i];
	}

	// Sắp xếp mảng tăng dần=============================
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	std::cout << "Mang sau khi sap xep tang dan:\n";
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	// Sắp xếp mảng giảm dần bằng Interchange Sort==============================
	//interchangeSortDescending(arr, n);
	//std::cout << "Mang sau khi sap xep giam dan:\n";
	//for (int i = 0; i < n; i++) {
	//	std::cout << arr[i] << " ";
	//}
	//std::cout << "\n";

	system("pause");
	return 0;
}

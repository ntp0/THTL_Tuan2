#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

const int MAX_SIZE = 100; 

void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

// Hàm sắp xếp mảng tăng dần bằng Selection Sort
void selectionSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		if (min_idx != i) {
			swap(arr[i], arr[min_idx]);
		}
	}
}

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

	selectionSort(arr, n);

	std::cout << "Mang sau khi sap xep tang dan theo Selection Sort:\n";
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	system("pause");
	return 0;
}

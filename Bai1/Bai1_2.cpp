#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createEvenArray(int n) {
	srand(time(NULL));

	int *arr = (int*)malloc(n * sizeof(int));
	if (arr == NULL) {
		printf("Khong du bo nho!\n");
		return NULL;
	}

	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 51 * 2; 
	}

	return arr;
}

int main() {
	int size;
	printf("Nhap so luong phan tu muon tao: ");
	scanf_s("%d", &size);

	int *array = createEvenArray(size);

	if (array != NULL) {
		printf("Mang duoc tao la: \n");
		for (int i = 0; i < size; i++) {
			printf("%d ", array[i]);
		}
		printf("\n");

		free(array);
	}
	system("pause");
	return 0;
}

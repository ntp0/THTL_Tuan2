#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createRandomArray(int *size) {
	srand(time(NULL));

	*size = rand() % 16 + 15;

	int *arr = (int*)malloc(*size * sizeof(int));
	if (arr == NULL) {
		printf("Khong du bo nho!\n");
		return NULL;
	}

	for (int i = 0; i < *size; i++) {
		arr[i] = rand() % 101; 
	}

	return arr;
}

int main() {
	int size;
	int *array = createRandomArray(&size);

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

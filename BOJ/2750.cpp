#include <stdio.h>
#include <stdlib.h>

int len;

void select(int arr[]) {
	int min, index,temp;
	for (int i = 0; i < len; i++) {
		min = 99999; // 난 min = arr[i]; 이렇게 하면 index = i; 이게 꼭 필요함! 반례 2 4 5 1 7 10 3 8 9 6
		for (int j = i; j < len; j++) {
			if (arr[j] < min) {
				min = arr[j];
				index = j;
			}
		}
		temp = arr[index];
		arr[index] = arr[i];
		arr[i] = temp;
	}
}

void bubble(int arr[]) {
	for (int i = len - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void quick(int arr[], int start, int end) {

	if (start >= end) return;

	int pivot = start, lindex = start + 1, rindex = end;
	while (lindex <= rindex) {
		while (lindex <= end && arr[lindex] <= arr[pivot])
			lindex++;

		while (rindex > start && arr[rindex] >= arr[pivot])
			rindex--;

		if (rindex < lindex) {
			int temp;
			temp = arr[pivot];
			arr[pivot] = arr[rindex];
			arr[rindex] = temp;
		}
		else {
			int temp;
			temp = arr[rindex];
			arr[rindex] = arr[lindex];
			arr[lindex] = temp;
		}

	}

	quick(arr, start, rindex - 1);
	quick(arr, rindex + 1, end);
}

void insert(int arr[]) {
	for (int j = 0; j < len - 1; j++) {
		int i = j;
		while (i>=0) {
			if (arr[i] > arr[i + 1]) {
				int temp;
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
			i--;
		}
	}

}

int main() {
	scanf("%d", &len);
	int *arr = (int *)malloc(sizeof(int)*len);
	for (int i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	insert(arr);
	for (int i = 0; i < len; i++)
		printf("%d\n", arr[i]);
}

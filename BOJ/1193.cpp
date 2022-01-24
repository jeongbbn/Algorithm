#include <stdio.h>

int main() {
	int n, x, arr[100000] = {0};
	scanf("%d", &n);
	for (x = 1; ; x++) {
		arr[x] = arr[x - 1] + x;
		if (n <= arr[x]) break;
	}
	if (x % 2 == 1) 
		printf("%d/%d", 1 + arr[x] - n, x - (arr[x] - n));
	else
		printf("%d/%d", x - (arr[x] - n),1 + arr[x] - n);
}

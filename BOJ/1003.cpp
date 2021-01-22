#include <stdio.h>
#include <memory.h>

typedef struct{
	int zero;
	int one;
}answer;

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int x;
		scanf("%d", &x);
		answer arr[41] = { 0 };
		arr[0].zero = 1;
		arr[1].one = 1;
		for (int i = 2; i <= x; i++) {
			arr[i].zero = arr[i - 1].zero + arr[i - 2].zero;
			arr[i].one = arr[i - 1].one + arr[i - 2].one;
		}
		printf("%d %d\n", arr[x].zero, arr[x].one);
		memset(arr, 0, sizeof(arr));
	}

}

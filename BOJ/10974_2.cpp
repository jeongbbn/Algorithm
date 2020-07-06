#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n;
int main() {
	scanf("%d", &n);
	int *arr = (int *)malloc(sizeof(int) *n);
	for (int i = 1; i <= n; i++)
		arr[i-1] = i;

	do {
		for (int i = 0; i < n; i++) 
			printf("%d ", arr[i]);
		printf("\n");
	} while (next_permutation(arr, arr + n));

}

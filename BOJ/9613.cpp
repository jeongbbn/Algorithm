#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int n, *arr;
		long long sum = 0;
		scanf("%d", &n);
		arr = (int *)malloc(sizeof(int)*n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				sum += gcd(arr[i], arr[j]);

		printf("%lld\n", sum);
		free(arr);
	}
}

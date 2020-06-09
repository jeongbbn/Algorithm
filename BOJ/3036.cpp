#include <iostream>
using namespace std;
int arr[101];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i < n; i++)
	{
		int x = gcd(arr[0], arr[i]);
		printf("%d", arr[0] / x);
		printf("/");
		printf("%d\n", arr[i] / x);
	}
}

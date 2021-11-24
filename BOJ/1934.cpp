#include <iostream>

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int x = gcd(a, b);
		int ans = a * b / x;
		printf("%d\n", ans);
	}
}

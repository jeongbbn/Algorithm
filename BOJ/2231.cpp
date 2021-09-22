#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int tmp = i;
		int sum = tmp;
		for (; tmp != 0; tmp /= 10)
		{
			sum += (tmp % 10);
		}
		if (sum == n) {
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
}

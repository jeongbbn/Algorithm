#include <bits/stdc++.h>
using namespace std;

long long d[65][10];
int main() {

	for (int i = 0; i < 10; i++) d[1][i] = 1;
	for (int i = 2; i <= 64; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				d[i][j] += d[i - 1][k];
			}
		}
	}

	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		int n;
		scanf("%d", &n);

		long long sum = 0;
		for (int k = 0; k < 10; k++)
		{
			sum += d[n][k];
		}
		printf("%lld\n", sum);
	}

}

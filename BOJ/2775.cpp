#include <iostream>
using namespace std;
int dp[15][15];
int main() {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		for (int j = 1; j <= b; j++)
			dp[0][j] = j;

		for (int k = 1; k <= a; k++)
			for (int j = 1; j <= b; j++)
				dp[k][j] = dp[k][j-1] + dp[k - 1][j];

		printf("%d\n", dp[a][b]);
	}
}

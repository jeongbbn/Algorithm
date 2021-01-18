#include <iostream>
#include <algorithm>
using namespace std;

long long dp[101][10];
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i < 10; i++)
		dp[0][i] = 1;
	dp[0][0] = 0;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0) dp[i][j] = dp[i-1][j + 1] % 1000000000;
			else if (j == 9) dp[i][j] = dp[i-1][j - 1] % 1000000000;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}
	long long cnt = 0;
	for (int i = 0; i < 10; i++) {
		cnt = (cnt + dp[n - 1][i]) % 1000000000;
	}

	printf("%d", cnt);


}

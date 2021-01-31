#include <iostream>
using namespace std;

long long dp[101];

int t;
int main() {

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		for (int i = 6; i <= n; i++)
		{
			dp[i] = dp[i - 5] + dp[i - 1];
		}
		printf("%lld\n", dp[n]);
	}

}

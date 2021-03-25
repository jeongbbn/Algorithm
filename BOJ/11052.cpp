#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001], arr[1001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}

	dp[1] = arr[1];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + arr[j]);
		}
	}
	printf("%d", dp[n]);
}

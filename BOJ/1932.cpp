#include <iostream>
#include <algorithm>
using namespace std;

int arr[505][505], n, dp[505][505];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			scanf("%d", &arr[i][j]);

	dp[1][0] = arr[1][0];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (j == 0) dp[i][j] = dp[i-1][j] + arr[i][j];
			else if (j == i-1) dp[i][j] = dp[i-1][j-1] + arr[i][j];
			else  dp[i][j] = max(dp[i-1][j-1] + arr[i][j], dp[i - 1][j] + arr[i][j]);
		}
	}

	printf("%d", *max_element(dp[n], dp[n] + n));

}

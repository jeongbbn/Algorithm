#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3], arr[1001][3];
int main() {
	int a;
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &arr[i][j]);

	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for (int i = 1; i < a; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}

	int ans = min(dp[a - 1][0], dp[a - 1][1]);
	ans = min(ans, dp[a - 1][2]);
	printf("%d", ans);

}

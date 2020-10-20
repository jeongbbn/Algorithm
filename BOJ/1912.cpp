#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[100'005], ans, dp[100'005];
int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	ans = arr[0];
	dp[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(0, dp[i - 1]) + arr[i];
		ans = max(ans, dp[i]);
	}
	printf("%d", ans);
}

#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
using namespace std;
#define INF 1e9+10

int dp[100005];
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		dp[i] = i;

	dp[0] = 0;
	for (int j = 1; j <= n; j++)
		for (int i = 1; i*i <= j; i++)
			dp[j] = min(dp[j], 1 + dp[j-i*i]);

	printf("%d", dp[n]);
}

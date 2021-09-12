#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000000
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int dp[1005], arr[1005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		dp[i] = INF;
	}
	
	dp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[j] + j >= i)
				dp[i] = min(dp[j] + 1, dp[i]);
		}
	}
	if (dp[n] == INF) printf("-1");
	else printf("%d", dp[n]);
}

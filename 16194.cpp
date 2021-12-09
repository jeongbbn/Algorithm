#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n;
int arr[1005], dp[1005];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	dp[1] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		dp[i] = arr[i];
		for (int j = 1; j <= i/2; j++)
		{
			dp[i] = min(dp[i], dp[j] + dp[i - j]);
		}
	}

	printf("%d", dp[n]);
} 

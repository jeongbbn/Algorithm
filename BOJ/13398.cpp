#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;

int n, dp[100005][2];
int arr[100005];
int maxx;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	dp[0][0] = arr[0];
	maxx = dp[0][0];

	for (int i = 1; i < n; i++)
	{
		dp[i][1] = max(dp[i-1][1]+arr[i], dp[i-1][0]);
		dp[i][0] = max(arr[i], dp[i - 1][0] + arr[i]);

		maxx = max(maxx, max(dp[i][1], dp[i][0]));
	}

	printf("%d", maxx);

}

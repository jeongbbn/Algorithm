#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, m;
int arr[2005];
int dp[2005][2005];

bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n) return 1;
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		//홀
		for (int j = 0; j <= n/2; j++)
		{
			if (outrange(i + j, i - j)) break;
			if (arr[i + j] != arr[i - j]) break;
			dp[i - j][i + j] = 1;
		}
		//짝
		if (outrange(i, i + 1)) continue;
		for (int j = 0; j <= n/2; j++)
		{
			if (outrange(i - j, i + 1 + j)) break;
			if (arr[i - j] != arr[i + 1 + j]) break;
			dp[i - j][i + 1 + j] = 1;
		}
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int s, e;
		scanf("%d%d", &s, &e);
		printf("%d\n", dp[s-1][e-1]);
	}
}

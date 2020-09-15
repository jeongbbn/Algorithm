#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int n, s, m;
int v[105];
bool dp[105][1005];
int main() {
	scanf("%d%d%d", &n, &s, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &v[i]);
	}


	if (s - v[1] >= 0)	dp[1][s - v[1]] = 1;
	if (s + v[1] <= m)	dp[1][s + v[1]] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			
			if (dp[i - 1][j] == 1) {
				if(j-v[i] >= 0) dp[i][j - v[i]] = 1;
				if(j+v[i] <= m) dp[i][j + v[i]] = 1;
			}
		}
	}

	for (int i = m; i >= 0; i--)
	{
		if (dp[n][i] == 1) {
			printf("%d", i); return 0;
		}
	}
	printf("-1");
}

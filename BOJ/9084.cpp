#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int n, tc, m;
int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		int v[25] = { 0, };
		int dp[10005] = { 0, };

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &v[i]);
		}
		scanf("%d", &m);

		dp[0] = 1;
		for (int j = 0; j < n; j++)
		{
			for (int i = v[j]; i <= m; i++)
			{
				dp[i] += dp[i - v[j]];
			}
		}
		printf("%d\n", dp[m]);
	}
}

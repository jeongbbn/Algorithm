#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<double, int>pi;
typedef pair<double, pair<int, int>>pii;
typedef long long ll;

int n, dp[55];
int main() {
	scanf("%d", &n);

	dp[0] = 1; dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] + 1) % mod;
	}
	printf("%d", dp[n]);
}

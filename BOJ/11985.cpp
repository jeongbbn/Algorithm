#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<string, bool>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

ll n, m, k;
vector<ll>v, dp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	v.resize(n); dp.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	dp[0] = k;
	for (int x = 1; x < n; x++)
	{
		dp[x] = dp[x - 1] + k;

		ll maxx = v[x], minn = v[x];
		for (int s = 2; s <= m; s++)
		{
			maxx = max(maxx, v[x - s + 1]);
			minn = min(minn, v[x - s + 1]);

			ll bfr = 0; if (x - s >= 0) bfr = dp[x - s];
			dp[x] = min(dp[x], k + (maxx - minn) * s + bfr);
			if (x - s < 0) break;
		}
	}
	cout << dp[n - 1];
}

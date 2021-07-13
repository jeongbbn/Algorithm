#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;

int c, n;
int dp[100005];
vector<pi>v;
int main() {
	cin >> c >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
		dp[a] = max(dp[a], b);
	}

	for (int x = 1; x < 100005; x++)
	{
		for (int i = 0; i < v.size(); i++)
		{
			int cost = v[i].first;
			int people = v[i].second;

			if (x - cost < 0) continue;
			dp[x] = max(dp[x], dp[x - cost] + dp[cost]);
		}
		if (dp[x] >= c){
			cout << x;
			break;
		}
	}
}

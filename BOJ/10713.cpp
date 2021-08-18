#include<bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int n, m, cnt[100005];
ll sum, ans;
vector<int>v;
vector<pii>cost;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a; cin >> a;
		v.push_back(a);
	}

	cost.resize(n);

	for (int i = 1; i < n; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		cost[i] = { a,{b,c} };
	}

	for (int i = 0; i < m - 1; i++)
	{
		int a = v[i], b = v[i + 1];
		if (a > b) swap(a, b);
		cnt[a]++;
		cnt[b]--;
	}

	for (int i = 1; i < n; i++)
	{
		sum += cnt[i];
		int ic = cost[i].second.second;
		int ic_cost = cost[i].second.first;
		int no_cost = cost[i].first;

		ans += min(sum * no_cost, sum * ic_cost + ic);
	}

	cout << ans;
}

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

ll n, c, arr[35], ans;
vector<ll>l, r;

void dfs(ll st, ll en, ll sum, vector<ll> &v) {
	if (sum > c) return;
	if (st == en) {
		if(sum != 0) v.push_back(sum);
		return;
	}
	dfs(st + 1, en, sum, v);
	dfs(st + 1, en, sum + arr[st], v);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> arr[i];

	dfs(0, n / 2, 0, l);
	dfs(n / 2, n, 0, r);

	ans = (ll)l.size() + (ll)r.size();
	sort(r.begin(), r.end());

	for (int i = 0; i < l.size(); i++)
	{
		ll x = c - l[i];
		ll pos = upper_bound(r.begin(), r.end(), x) - r.begin();
		ans += pos;
	}
	cout << ans + 1;
}

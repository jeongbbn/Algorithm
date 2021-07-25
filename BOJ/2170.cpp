#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<pi, int>pii;

int n, x, y, minn , maxx, ans;
vector<pi>v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end());

	minn = v[0].first;
	maxx = v[0].second;
	for (int i = 1; i < n; i++)
	{
		if (maxx < v[i].first) {
			ans += maxx - minn;
			minn = v[i].first;
		}
		maxx = max(maxx, v[i].second);
	}
	ans += maxx - minn;
	cout << ans;
}

#include <bits/stdc++.h>
using namespace std;
#define INF 1e12
#define mod 10007
typedef long long ll;
typedef pair<ll, ll>pi;
typedef pair<int, pi>pii;

ll n, m, sum, ans = INF, bfr, samesum, money; 
vector<pi>v;
bool flag;

bool cmp(pi a, pi b) {
	if (a.first != b.first) return a.first < b.first;
	else return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		ll a, b; cin >> a >> b;
		v.push_back({ b,a });
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		if (bfr != v[i].first) {
			sum += v[i].second;
			money = v[i].first;
			bfr = v[i].first;
		}
		else {
			sum += v[i].second;
			money += v[i].first;
		}

		if (sum >= m) {
			flag = 1; ans = min(ans, money);
		}
	}
	if(flag) cout << ans;
	else cout << -1;
}

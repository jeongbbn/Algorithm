#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

int l, n, f, b, maxx;
ll ans, diff, cnt;
pi arr[100005];
vector<pi>v;

int main() {
	cin >> l >> n >> f >> b;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	diff = f - b;
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i].second > maxx) {
			v.push_back({ arr[i].second, arr[i].first });
			maxx = arr[i].second;
		}
	}

	reverse(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		ans += (v[i].first * (v[i].second - cnt) * diff);
		cnt = v[i].second;
	}

	printf("%lld", ans);
}

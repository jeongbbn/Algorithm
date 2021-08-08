#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1'000'000'005

ll ans = MAX, st, en;
int n, k;
vector<int>v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}

	en = 20;
	while (st + 1 < en) {
		ll mid = (st + en) / 2;

		int cnt = 0, l = 0;
		ll sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[i] - v[l] + 1 > mid) {
				sum += (ll)(v[i - 1] + 1 - v[l]);
				l = i; cnt++;
			}
		}

		sum += (ll)(v[n - 1] + 1 - v[l]);
		cnt++;

		if (cnt > k) st = mid;
		else {
			en = mid;
			ans = min(ans, sum);
		}
	}
	cout <<ans;
}

/*
10 5
1
2
4
6
8
10
13
15
16
19

13
*/

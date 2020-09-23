#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000000
typedef pair<string, bool>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int t, win[1005], lose[1005];

int main() {
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		fill(win, win + 1005, 0);
		fill(lose, lose + 1005, 0);

		for (int i = 0; i < m; i++)
		{
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			win[a] += c; lose[b] += c; 
			lose[a] += d; win[b] += d;
		}

		vector<int>v;
		for (int i = 1; i <= n; i++)
		{
			ll s = win[i] * win[i];
			ll a = lose[i] * lose[i];

			if (a == 0 && s == 0) v.push_back(0); 
			else v.push_back(s * 1000 / (a + s));
		}

		ll minn = v[0];
		ll maxx = v[0];
		for (int i = 1; i < v.size(); i++)
		{
			if (minn > v[i]) minn = v[i];
			if (maxx < v[i]) maxx = v[i];
		}

		printf("%lld\n%lld\n", maxx, minn);
	}
}

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<double, int>pi;
typedef pair<double, pair<int, int>>pii;
typedef long long ll;

int n, t;
ll ans = -1;

/*
반례
1 2
1 1 1
*/
int main() {
	scanf("%d%d", &n, &t);
	for (int i = 0; i < n; i++)
	{
		ll a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);

		ll x = t - a;
		if (x < 0) {
			if (ans == -1) ans = a - t;
			else ans = min(a - t, ans);
		}
		else {
			ll y = x / b;
			if (x % b != 0) y++;
			if (y >= c) continue;
			if (ans == -1) ans = a + y * b - t;
			else ans = min(a + y * b - t, ans);
		}
	}
	printf("%lld", ans);
}

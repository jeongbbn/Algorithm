#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

ll x, y, w, s, ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x >> y >> w >> s;
	ans = (x + y) * w;

	ll minn = min(x, y), diff = max(x, y) - min(x, y);
	ans = min(ans, minn * s + diff * w);
	ans = min(ans, minn * s + (diff / 2)*s * 2 + (diff % 2) * w);
	cout << ans;
}

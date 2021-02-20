#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

int n, h, ans = INF, cnt;
vector<int>low, up;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> h;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		if (i % 2 == 0) low.push_back(a);
		else up.push_back(h - a + 1);
	}
	
	sort(up.begin(), up.end());
	sort(low.begin(), low.end());

	int N = n / 2;
	for (int now = 1; now <= h; now++)
	{
		int p1 = lower_bound(low.begin(), low.end(), now) - low.begin();
		int p2 = upper_bound(up.begin(), up.end(), now) - up.begin();

		if (ans > N - p1 + p2) {
			ans = N - p1 + p2;
			cnt = 1;
		}
		else if (ans == N - p1 + p2) cnt++;
	}
	cout << ans << " " << cnt;
}

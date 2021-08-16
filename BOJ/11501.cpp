#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

ll tc, n;
vector<int>v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<int> v, arr;
		arr.resize(n + 1); v.resize(n + 1);
		for (int i = 0; i < n; i++) cin >> arr[i];

		int minn = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (minn >= arr[i]) v[i] = minn;
			else minn = v[i] = arr[i];
		}

		ll ans = 0;
		for (int i = 0; i < n; i++) ans += v[i] - arr[i];

		cout << ans << "\n";
		arr.clear(); v.clear();
	}
}

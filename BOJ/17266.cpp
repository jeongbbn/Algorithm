#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int>pi;
typedef long long ll;
#define INF 1e9

int n, m, arr[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> arr[i];

	int st = 0, en = n, ans = INF;
	while (st <= en) {
		int mid = (st + en) / 2;

		int l = arr[0] - mid, r = arr[0] + mid;
		for (int i = 1; i < m; i++)
			if (arr[i] - mid <= r) r = arr[i] + mid;

		if (l <= 0 && n <= r) {
			ans = min(ans, mid);
			en = mid - 1;
		}
		else st = mid + 1;
	}
	cout << ans;
}

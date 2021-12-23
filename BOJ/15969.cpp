#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<pi, int>pii;

int n, maxx, minn = 1003;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		minn = min(minn, a);
		maxx = max(maxx, a);
	}
	cout << maxx - minn;
}

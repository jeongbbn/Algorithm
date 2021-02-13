#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<string, bool>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, ans = INF;
vector<int>arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n * 2; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++)
		ans = min(ans, arr[i] + arr[2*n - i - 1]);

	cout << ans;
}

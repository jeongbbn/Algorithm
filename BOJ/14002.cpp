#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<pi, int>pii;

int n, arr[1005], dp[1005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	int ans = *max_element(dp, dp + n);
	cout << ans << "\n";

	int bfr = INF;
	vector<int>v;
	for (int i = n - 1; i >= 0; i--)
	{
		if (ans == dp[i] && bfr > arr[i]) {
			ans--; bfr = arr[i];
			v.push_back(arr[i]);
		}
	}

	for (int i = (int)v.size() - 1; i >= 0; i--) cout << v[i] << " ";
}

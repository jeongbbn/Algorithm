#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

ll n, arr[100'005], dp[100'005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1);

	dp[1] = arr[1];
	for (int x = 2; x <= n; x++)
	{
		dp[x] = max(dp[x - 1] + arr[x], dp[x - 2] + arr[x] * arr[x - 1]);
	}
	cout << dp[n];
}

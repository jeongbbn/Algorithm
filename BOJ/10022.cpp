#include<bits/stdc++.h>
using namespace std;

int n, k, ans;
int arr[405][405], dp[405][405];

bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n) return 1;
	return 0;
}

int upper(int x, int y) {
	int cnt = 0;
	for (int i = 0; i <= k; i++) {
		if (!outrange(x-i, y+i)) cnt += arr[x - i][y + i];
	}
	return cnt;
}

int lower(int x, int y) {
	int cnt = 0;
	for (int i = 0; i <= k; i++)
		if (!outrange(x + i, y + i)) cnt += arr[x + i][y + i];
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	dp[0][0] = arr[0][0];
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= i; j++) {
			if(!outrange(i-j, j)) dp[0][0] += arr[i - j][j];
		}
	}

	ans = max(ans, dp[0][0]);

	//move to bottom
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = dp[i - 1][0] + upper(i + k, 0) - lower(i - k - 1, 0);
		ans = max(dp[i][0], ans);
	}

	//move to right
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (!outrange(i,j-k-1)) dp[i][j] += arr[i][j - k - 1];
			dp[i][j] += dp[i][j - 1] - (upper(i, j - k - 1) + lower(i, j - k - 1))
				+ (upper(i + k, j) + lower(i - k, j));
			if (!outrange(i,j + k)) dp[i][j] -= arr[i][j + k];
			ans = max(dp[i][j], ans);
		}
	}

	cout << ans;
}

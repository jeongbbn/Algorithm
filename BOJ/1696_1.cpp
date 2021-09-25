#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, arr[505][505], dp[505][505];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}

	dp[0][0] = arr[0][0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j - 1 >= 0) dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
			dp[i][j] = max(dp[i - 1][j] + arr[i][j], dp[i][j]);
		}
	}
	
	cout << *max_element(dp[n - 1], dp[n - 1] + n);
}

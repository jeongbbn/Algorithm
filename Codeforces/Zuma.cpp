/*
Codeforces Round #336 (Div. 1)
B. Zuma

https://codeforces.com/blog/entry/64228?
https://codeforces.com/blog/entry/22256
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 1e9
typedef long long ll;
int arr[505], dp[505][505];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int len = 1; len <= n; len++)
	{
		for (int i = 0, j = len - 1; j < n; i++, j++)
		{
			if (len == 1) { dp[i][i] = 1; continue; }
			dp[i][j] = 1 + dp[i + 1][j];
			for (int k = i + 1; k <= j; k++)
			{
				if (k == i + 1 && arr[i] == arr[k]) {
					dp[i][j] = min(dp[i][j], 1 + dp[i + 2][j]);
				}
				else if (arr[i] == arr[k]) {
					dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
				}
			}
		}
	}

	printf("%d", dp[0][n - 1]);
}

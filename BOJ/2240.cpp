#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000000
typedef pair<string, bool>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int t, w;
int arr[1005];
int dp[1005][35][3];
int main() {
	scanf("%d%d", &t, &w);
	for (int i = 1; i <= t; i++)
		scanf("%d", &arr[i]);

	if (arr[1] == 1) dp[1][0][1] = 1;
	else dp[1][1][2] = 1;

	for (int i = 2; i <= t; i++) //arr 배열 인덱스
	{
		for (int j = 0; j <= w; j++) //이동 횟수
		{
			if (arr[i] == 1) {
				dp[i][j][1] = max(dp[i - 1][j][1] + 1, dp[i - 1][j - 1][2] + 1);
				dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][1]);
			}
			else {
				if (j == 0) continue;
				dp[i][j][2] = max(dp[i - 1][j][2] + 1, dp[i - 1][j - 1][1] + 1);
				dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= w; i++)
		for (int j = 1; j <= 2; j++)
			ans = max(dp[t][i][j], ans);

	printf("%d", ans);
}

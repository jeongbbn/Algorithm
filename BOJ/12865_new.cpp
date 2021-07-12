#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define	mod 1000000007;

/*
dp[배낭 인덱스][현재 무게] = 배낭 인덱스까지 봤을때, 현재 무게까지의 최대 value 값

4 7
6 13
4 8
3 6
5 12

first iteration
dp[1][6] = 13
dp[1][7] = 13 (현재 무게가 7일 때, 최대 value값은 6무게에서 구한 value 6)

second iteration
dp[2][4] = 8
dp[2][5] = 8
dp[2][6] = 13
dp[2][7] = 13

third iteration
dp[3][3] = 6
dp[3][4] = 8
dp[3][5] = 8
dp[3][6] = 13
dp[3][7] = 14

fourth iteration
dp[4][3] = 6
dp[4][4] = 8
dp[4][5] = 12
dp[4][6] = 13
dp[4][7] = 14
*/

int n, c, dp[105][100005];
pi arr[105];
int main() {
	scanf("%d%d", &n, &c);

	for (int i = 1; i <= n; i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);

	for (int i = 1; i <= n; i++)
	{
		int w = arr[i].first;
		int v = arr[i].second;

		for (int x = 1; x <= c; x++)
		{
			//이번 물건을 선택 안하는 경우
			dp[i][x] = max(dp[i][x], dp[i - 1][x]);

			//이번 물건을 선택하는 경우
			if (x - w >= 0) dp[i][x] = max(dp[i][x], dp[i - 1][x - w] + v);
		}
	}

	//n,c까지 왔을 때의 최대 value값을 구하는 것이다.
	printf("%d", dp[n][c]);
}

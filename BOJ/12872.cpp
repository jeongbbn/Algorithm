#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define digit 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, m, p;
long long dp[105][105]; //[지금까지 선택한 노래의 수(P)][N개의 노래 중 선택된 노래의 개수]
int main() {
	scanf("%d%d%d", &n, &m, &p);

	dp[1][1] = n;
	for (int i = 1; i < p; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			//새로운 문자를 추가하는 경우
			if (j + 1 <= n) {
				dp[i + 1][j + 1] = (dp[i + 1][j + 1] + (dp[i][j] * (n - j)) % digit) % digit;
			}
			//썼던 문자 또 쓰는 경우
			if (j - m > 0 && n < p){
				if (i + 1 > p - n + j && j < n) continue;
				dp[i + 1][j] = (dp[i + 1][j] + (dp[i][j] * (j - m)) % digit) % digit;
			}
		}
	}

	printf("%lld", dp[p][n]);
}

#include <bits/stdc++.h>
using namespace std;

int dp[35][35], R, C, W;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    //문제에서는 R번째 줄에서 C번째 원소를 의미하지만,
    //실제 파스칼 삼각형과 맞추기 위해서는 R-1, C-1이라고 생각해야한다.
    //(ex, 문제에서 가장 최상단 점이 1번째 줄 1번 원소이지만
    //파스칼 삼각형으로 치면 0C0로 0번째 줄 0번이라고 생각함.)
    
    dp[0][0]=1;
	for (int i = 1; i <= 30; i++)
	{
        //nC0, nCn은 둘 다 1이다.
		dp[i][0] = 1; dp[i][i] = 1;
		for (int j = 1; j < i; j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
	}

	cin >> R >> C >> W;
	
	long long ans = 0;
	for (int i = 0; i < W; i++)
		for (int j = 0; j < i + 1; j++) {
			ans += dp[R - 1 + i][C - 1 + j];
		}

	cout << ans;
}

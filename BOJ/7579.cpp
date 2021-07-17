#include <bits/stdc++.h>
using namespace std;

/*
	dp[비용] = 메모리
	이 때, bottom-up으로 풀게 되면, 이번 차례에 바꾼 것이 그대로 반영되게 된다.
	(ex. 
	x = 1;
	dp[1] = x; <- update
	dp[2] = dp[1] + x <- 동일한게 여러번 들어간다.

	==> 따라서, 뒤에서 부터 top-down 방식으로 채워나가면 된다.
	dp[60] = dp[59] + arr[1];
	dp[59] = dp[58] + arr[1] ,,,,,,,,

	이 때, 채워져있는 dp 배열에 대해서만 업데이트가 일어나도록 -1로 전처리를 해줬다.
*/

int N, M, dp[10005];
vector<int>mem, cost;
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int a; cin >> a;
		mem.push_back(a);
	}

	for (int i = 0; i < N; i++)
	{
		int a; cin >> a;
		cost.push_back(a);
	}

	for (int x = 10000; x >= 0; x--) dp[x] = -1;
	dp[0] = 0;

	for (int i = 0; i < N; i++)
	{
		int c = cost[i];
		int m = mem[i];

		for (int x = 10000; x >= 0; x--)
		{
			if (x - c >= 0 && dp[x - c] >= 0) {
				dp[x] = max(dp[x], dp[x - c] + m);
			}
		}
	}

	for (int i = 0; i <= 10000; i++)
	{
		if (dp[i] >= M) {
			cout << i;
			return 0;
		}
	}
}

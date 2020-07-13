#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define digit 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int t, n;
long long dp[35][35];
long long dfs(int half ,int one) {
	if (dp[half][one] != -1) return dp[half][one];
	if (one == 0) return 1;
	// half:5, one:0처럼 one이 0인 경우엔, 5->4->3->2->1->0라서
	// 그냥 바로 1 return 해줘도 된다.
	dp[half][one] = 0; 

	if (half - 1 >= 0) {
		dp[half][one] += dfs(half - 1, one);
	}
	//if (one - 1 >= 0)안해줘도 된다. 어차피 one = 0이면 return 1 되게 되어있으니까,
	//one이 음수로 내려갈 일은 없다.
	dp[half][one] += dfs(half + 1, one - 1);

	return dp[half][one];
}

void init() {
	for (int i = 0; i <= 30; i++)
	{
		for (int j = 0; j <= 30; j++)
		{
			dp[i][j] = -1;
		}
	}
}
int main() {
	init();
	while(1){
		scanf("%d", &n);
		if (n == 0) break;
		printf("%lld\n", dfs(0, n));
	}
	
}

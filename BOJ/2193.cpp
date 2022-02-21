#include <iostream>
using namespace std;
//1다음에는 무조건 0 따라서 n-2, 0다음에는 0,1 둘 다 가능 따라서 n-1
long long dp[91];
int main() {
	int n;
	scanf("%d", &n);

	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	printf("%lld", dp[n]);
}

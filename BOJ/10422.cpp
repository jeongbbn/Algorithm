#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define digit 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n;
long long dp[5005];

int main() {

	dp[0] = 1;
	dp[2] = 1;
	for (int i = 4; i <= 5000; i+=2)
	{
		for (int j = 2; j <= i; j+=2)
		{
			dp[i] += (dp[j-2] * dp[i - j]) % digit;
			dp[i] %= digit;
		}
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		printf("%lld\n", dp[a]);
	}

}

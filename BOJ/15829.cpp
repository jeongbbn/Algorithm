#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

long long dp[30];
int main() {
	int n;
	char str[55];
	scanf("%d", &n);
	scanf("%s",str);

	dp[0] = 1;
	for (int i = 1; i < 50; i++)
	{
		dp[i] = (dp[i - 1] * 31) % 1234567891;
	}

	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += ((str[i] - 96)*dp[i]) % 1234567891;
	}
	printf("%lld", sum % 1234567891);
	return 0;

}

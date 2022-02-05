#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

pi dp[35];
int main() {
	int d, k;
	scanf("%d%d", &d, &k);

	dp[1] = { 1,0 };
	dp[2] = { 0,1 };

	for (int i = 3; i <= d; i++)
	{
		dp[i].first = dp[i - 1].first + dp[i - 2].first;
		dp[i].second = dp[i - 1].second + dp[i - 2].second;
	}

	int a, b;
	for (a = 1; a < k; a++)
	{
		b = k - (a * dp[d].first);
		if (b%dp[d].second == 0) { b = b / dp[d].second; break; }
	}

	printf("%d\n%d", a, b);
}

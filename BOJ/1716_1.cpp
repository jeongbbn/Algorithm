#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<map>
#include <string>
using namespace std;
#define INF 1e12
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int arr[300005];
int pizza[300005];
int dp[300005];

int main() {
	int d, n;
	scanf("%d%d", &d, &n);
	for (int i = 0; i < d; i++)
	{
		scanf("%d", &arr[i]);
	}

	dp[0] = arr[0];
	for (int i = 1; i < d; i++)
	{
		dp[i] = min(dp[i - 1], arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &pizza[i]);
	}

	int j = 0;
	for (int i = d-1; i >= 0; i--)
	{
		if (dp[i] < pizza[j]) continue;
		else { j++; }
		if (j == n) {
			printf("%d", i + 1); return 0;
		}
	}
	printf("0");
}

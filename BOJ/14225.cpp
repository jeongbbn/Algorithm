#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n;
int arr[25];
bool ans[20000005];
bool visit[25];

int sum = 0;
void dfs(int k, int idx, int en) {
	if (k == en) {
		ans[sum] = 1;
		return ;
	}
	
	for (int i = idx; i < n; i++)
	{
		if (visit[i]) continue;
		visit[i] = 1;
		sum += arr[i];
		dfs(k + 1, i, en);
		sum -= arr[i];
		visit[i] = 0;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);

		ans[arr[i]] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		dfs(0, 0, i);
	}

	for (int i = 1; i <= 20000000; i++)
	{
		if (!ans[i]) { printf("%d", i); return 0; }
	}
}

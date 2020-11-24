#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, sum, ans = INF;
int arr[15][15];
bool visit[15];

void dfs(int x, int sum, int cnt) {

	if (cnt == n) {
		if (arr[x][0] != 0)
			ans = min(ans, sum + arr[x][0]);
		return;
	}

	visit[x] = 1;
	for (int i = 0; i <= n; i++)
	{
		if (arr[x][i] > 0 && !visit[i]) {
			if (sum + arr[x][i] < ans)
				dfs(i, sum + arr[x][i], cnt + 1);
		}
	}
	visit[x] = 0;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);

	dfs(0, 0, 1);
	printf("%d", ans);
}

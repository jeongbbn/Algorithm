#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;
typedef pair<double, pair<int, int>> pii;

int ans = -1;
int idx;
vector<pi>adj[10005];
int par[10005];

int dfs(int a, int sum) {
	for (int i = 0; i < adj[a].size(); i++)
	{
		int x = adj[a][i].first;
		int cost = adj[a][i].second;
		if (x == par[a]) continue;

		par[x] = a;
		sum += cost;
		dfs(x, sum);
		sum -= cost;
		par[x] = 0;
	}

	if (ans < sum) {
		ans = sum;
		idx = a;
	}
	return idx;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b,&c);
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	
	int tmp = dfs(1, 0);
	ans = -1;
	dfs(tmp, 0);

	printf("%d", ans);
}

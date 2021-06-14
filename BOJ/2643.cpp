#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n;
pi arr[105];
bool visit[105];

bool cmp(pi x, pi y) {
	if (x.first == y.first) return x.second > y.second;
	return x.first > y.first;
}

int dfs(int x, int len) {
	visit[x] = 1;
	
	for (int i = 0; i < n; i++)
	{
		if (visit[i]) continue;
		if (arr[x].second > arr[i].first) {
			visit[i] = 1;
			dfs(i, len++);
		}
	}
	return len;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &arr[i].first, &arr[i].second);
	}

	sort(arr, arr + n, cmp);

	int ans = 0;
	for (int i = 0; i < n; i+	+)
	{
		fill(visit, visit + n, 0);
		int tmp = dfs(i, 1);
		ans = max(tmp, ans);
	}

	printf("%d", ans);
}

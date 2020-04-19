#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
using namespace std;
#define INF 1e9+10

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		int indegree[1005] = { 0, };
		int n, k;
		scanf("%d%d", &n, &k);
		int arr[1005] = { 0, }, dp[1005];


		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
			dp[i] = -1;
		}

		vector<int>adj[1005];
		for (int i = 0; i < k; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			indegree[b]++;
		}
		int end;
		scanf("%d", &end);

		queue<int>q;
		for (int i = 1; i <= n; i++)
		{
			if (indegree[i] == 0) {
				q.push(i);
				dp[i] = arr[i];
			}
		}

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			if (now == end) break;

			for (int i = 0; i < adj[now].size(); i++)
			{
				int nxt = adj[now][i];
				indegree[nxt]--;
				dp[nxt] = max(dp[nxt], dp[now] + arr[nxt]);
				if (indegree[nxt] == 0) q.push(nxt);
			}
		}
		printf("%d\n", dp[end]);
	}
}

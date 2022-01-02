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
		int indegree[505] = { 0, };
		int n;
		scanf("%d", &n);
		int arr[505];
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		vector<int>adj[505];
		for (int i = 0; i < n-1; i++)
			for (int j = i + 1; j < n; j++) {
				adj[arr[i]].push_back(arr[j]);
				indegree[arr[j]]++;
			}

		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			bool flag = false;
			for (int i = 0; i < adj[a].size(); i++)
			{
				if (adj[a][i] == b) {
					indegree[b]--;
					adj[a][i] = 0;

					indegree[a]++;
					adj[b].push_back(a);
					flag = true;
				}
			}

			if (!flag) {
				for (int i = 0; i < adj[b].size(); i++)
				{
					if (adj[b][i] == a) {
						indegree[a]--;
						adj[b][i] = 0;

						indegree[b]++;
						adj[a].push_back(b);
					}
				}
			}
		}

		queue<int>q;
		bool rflag = false;
		for (int i = 1; i <= n; i++)
			if (indegree[i] == 0) { q.push(i); }

		vector<int>ans;
		while (!q.empty()) {
			int now=q.front();
			ans.push_back(now);
			q.pop();

			for (int i = 0; i < adj[now].size(); i++)
			{
				int nxt = adj[now][i];
				if (nxt == 0) continue;
				indegree[nxt]--;

				if (indegree[nxt] == 0) q.push(nxt);
			}

		}

		if(ans.size()!=n) { printf("IMPOSSIBLE\n"); continue; }

		for (int i = 0; i < ans.size(); i++)
		{
			printf("%d ",ans[i]);
		}
		printf("\n");

	}
}

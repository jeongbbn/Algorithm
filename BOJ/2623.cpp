#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, k;
int indegree[1005], arr[1005];
vector<int>adj[1005], ans;
queue<int>q;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &k);
		for (int i = 0; i < k; i++)
			scanf("%d", &arr[i]);
		for (int i = 0; i < k-1; i++) {
			adj[arr[i]].push_back(arr[i + 1]);
			indegree[arr[i + 1]]++;
		}
	}

	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0) q.push(i);

	while (!q.empty()) {
		int x = q.front();
		ans.push_back(x);
		q.pop();
		for (int i = 0; i < adj[x].size(); i++)
		{
			int y = adj[x][i];
			indegree[y]--;
			if (indegree[y] == 0) q.push(y);
		}
	}
	if (ans.size() != n) {
		printf("0"); return 0;
	}

	for (int i = 0; i < n; i++)
		printf("%d\n", ans[i]);


}

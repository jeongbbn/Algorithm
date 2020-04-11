#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<map>
#include <string>
using namespace std;
typedef pair<int, int>pii;

bool check[55];
vector<int>adj[55], party[55];
bool visit[55];
bool bfs(int x) {
	queue<int>q;
	visit[x] = 1;
	q.push(x);

	bool flag=true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (check[cur]) {
			flag = false; break;
		}

		for (int i = 0; i < adj[cur].size(); i++)
		{
			int nxt = adj[cur][i];
			if (visit[nxt]) continue;
			visit[nxt] = 1;
			q.push(nxt);
		}
	}
	return flag;
}

int main() {
	int n,m, t;
	scanf("%d%d", &n,&m);
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int a;
		scanf("%d", &a);
		check[a] = 1;
	}

	for (int i = 0; i < m; i++)
	{
		int a;
		scanf("%d", &a);
		int* tmp = (int *)malloc(sizeof(int)*a);
		for (int j = 0; j < a; j++) {
			scanf("%d", &tmp[j]);
			party[i].push_back(tmp[j]);
		}

		for (int j = 0; j < a-1; j++) {
			adj[tmp[j]].push_back(tmp[j + 1]);
			adj[tmp[j+1]].push_back(tmp[j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		bool chk = bfs(i);
		if (!chk) {
			for (int j = 1; j <= n; j++)
			{
				if (visit[j]) check[j] = 1;
			}
		}
		for (int j = 1; j <= n; j++)
			visit[j] = 0;
	}
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < party[i].size(); j++)
		{
			if (check[party[i][j]]) {
				cnt--; break;
			}
		}
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}

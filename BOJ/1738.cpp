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
typedef pair<int,pair<int, int>>pii;

vector<pi>adj[105];
long long dist[105];
int ans[105];
vector<int>ans, minuss;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({ b,-c });
	}

	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
	}
	dist[1] = 0;
	ans[1] = 1;

	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k < adj[j].size(); k++)
			{
				int nxt = adj[j][k].first;
				int cost = adj[j][k].second;

				if (dist[j] != INF && dist[nxt] > dist[j] + cost){
					dist[nxt] = dist[j] + cost;
					ans[nxt] = j;	
					if (i == n - 1) minuss.push_back(j);
					//만약 혼자 떨어져있는 정점이었다면 INF라서 if문 통과를 못함
					//여기에 왔다는 것 자체가 시작점과 이어져 있다는 뜻
				}
			}
		}
	}

	
	for (int i = 0; i < minuss.size(); i++)
	{
		queue<int>q;
		bool qvisit[105] = { 0, };
		q.push(minuss[i]);
		qvisit[minuss[i]] = 1;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			if (cur == n) { flag = true; break; }
			for (int j = 0; j < adj[cur].size(); j++)
			{
				int nxt = adj[cur][j].first;
				if (nxt == cur) continue;
				if (qvisit[nxt]) continue;
				q.push(nxt);
				qvisit[nxt] = 1;
			}
		}

		if (flag) {
			printf("-1"); 
			return 0;
		}
	}
	ans.push_back(n);
	int i = n;
	while (i!=1) {
		ans.push_back(ans[i]);
		i = ans[i];
	}

	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}
}

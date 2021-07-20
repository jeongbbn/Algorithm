#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<map>
#include <string>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, m;
vector<int>adj[1005];
int indegree[1005];
int s[1005];
queue<int>q;
int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d%", &a, &b);
		adj[a].push_back(b);
		indegree[b]++;
	}

	int cnt = 1;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0) { 
			q.push(i); 
			s[i] = cnt;
		}
	}

	while (1) {
		int size = q.size();
		if (size == 0) break;
		cnt++;
		while (size--) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < adj[x].size(); i++)
			{
				int y = adj[x][i];
				indegree[y]--;
				s[y] = cnt;
				if (indegree[y] == 0) q.push(y);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", s[i]);
	}
}

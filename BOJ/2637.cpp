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

int n, m, k;
int arr[25][25];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };

bool outrange(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>n - 1) return 1;
	return 0;
}

int toMake[105][105];
int indegree[105];
bool ans[105];
vector<int>adj[105];
int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[b].push_back(a);
		indegree[a]++;
		toMake[a][b] = c;
	}

	queue<int>q;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0) {
			q.push(i); ans[i] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		int x = q.front();
		q.pop();

		for (int j = 0; j < adj[x].size(); j++)
		{
			int nxt = adj[x][j];
			
			if (!ans[x]) {
				for (int k = 1; k <= n; k++)
				{
					if(ans[k])
					toMake[nxt][k] += toMake[x][k] * toMake[nxt][x];
				}
			}
			indegree[nxt]--;
			if (indegree[nxt] == 0) q.push(nxt);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == 1) {
			printf("%d %d\n", i, toMake[n][i]);
		}
	}
}

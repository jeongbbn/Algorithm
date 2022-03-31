#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<map>
#include <string>
#include<math.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

vector<int>lower[100005], upper[100005];
queue<int>q;
int bfs(int a, vector<int>adj[]) {
	bool visit[100005] = { 0, };
	visit[a] = 1;
	q.push(a);

	int cnt = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < adj[x].size(); i++)
		{
			int nx = adj[x][i];

			if (visit[nx]) continue;
			visit[nx] = 1;
			q.push(nx);
			cnt++;
		}
	}

	return cnt;
}

int main() {
	int u,v,x;
	scanf("%d%d%d", &u,&v,&x);
	
	for (int i = 0; i < v; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		lower[a].push_back(b);
		upper[b].push_back(a);
	}

	int low = u - bfs(x, lower);
	int up = bfs(x, upper) + 1;

	printf("%d %d", up, low);


}

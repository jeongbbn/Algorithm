#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool check[105];
vector<int>v[105];
int n, x, y;
queue<pair<int, int>>q;
void bfs(int k) {
	check[k] = 1;
	q.push({ k,0 });
	while (!q.empty()) {
		int z = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (z == y) {
			printf("%d", dist);
			return;
		}

		for (int i = 0; i < v[z].size(); i++)
		{
			int nz = v[z][i];
			if (check[nz]) continue;
			q.push({ nz,dist + 1});
			check[nz] = 1;
		}

	}

	printf("-1");
	return;

}


int main() {
	scanf("%d", &n);
	scanf("%d%d", &x, &y);
	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs(x);
}

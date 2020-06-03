#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
using namespace std;
typedef pair<int, pair<int, int>>p;
#define INF 1e9+10

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n;
bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)return 1;
	return 0;
}
int cnt;
int main() {
	while (1) {
		cnt++;
		scanf("%d", &n);
		if (n == 0) break;

		int arr[130][130], mindist[130][130];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				mindist[i][j]=INF;

		mindist[0][0] = arr[0][0];

		priority_queue<p, vector<p>, greater<p>>pq;
		pq.push({ arr[0][0],{0,0} });
	
		while (!pq.empty()) {
			int dist = pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();

			if (dist != mindist[x][y]) continue;

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				int cost = arr[nx][ny];

				if (outrange(nx, ny)) continue;

				if (mindist[nx][ny] > dist + cost) {
					mindist[nx][ny] = dist + cost;
					pq.push({ mindist[nx][ny],{nx,ny} });
				}
			}
		}
		printf("Problem %d: %d\n", cnt, mindist[n - 1][n - 1]);


	}
}

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
	if (x<0 || y<0 || x>n - 1 || y>n-1) return 1;
	return 0;
}

int states = 2;

pii eat(int a, int b, int c) {
	queue<pii>q;
	bool visit[25][25] = { 0, };
	visit[a][b] = 1;
	q.push({ c,{a,b} });

	int mini = INF;
	int minj = INF;
	int mindist = INF;

	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int dist = q.front().first;
		q.pop();

		if (mindist < dist) return { mindist,{mini,minj} };

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) continue;
			if (visit[nx][ny]) continue;
			if (arr[nx][ny] > states && arr[nx][ny]!=9) continue;
			else if (arr[nx][ny] == states || arr[nx][ny]==0 || arr[nx][ny]==9) {
				q.push({ dist + 1, {nx,ny} });
				visit[nx][ny] = 1;
			}
			else {
				if (mindist > dist+1) {
					mindist = dist+1;
					mini = nx; minj = ny;
				}
				else if (mindist == dist+1) {
					if(mini > nx) { mini = nx; minj = ny; }
					else if(mini==nx) { if(minj>ny ) { mini = nx; minj = ny; }}
				}
				
			}
		}
	}
	return { mindist,{mini,minj} };
}

int main() {
	scanf("%d", &n);
	int stx, sty;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 9) {stx = i; sty = j;}
		}

	pii p = eat(stx, sty, 0);
	int cnt = 0;
	int ans = INF;
	while (1) {
		if (p.first == INF) break;
		arr[p.second.first][p.second.second] = 0;
		cnt++;
		if (cnt == states) { states++; cnt = 0; }
		ans = p.first;
		p = eat(p.second.first, p.second.second, ans);
	}
	if (ans == INF) ans = 0;
	printf("%d", ans);
}

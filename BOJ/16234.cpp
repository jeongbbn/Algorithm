#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<map>
#include<math.h>
#include <string>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, l, r;
int arr[55][55];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
bool flag = false;
bool outrange(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>n - 1) return 1;
	return 0;
}

bool visit[55][55];
queue<pi>q;
queue<pi>tmp;
void bfs(int a, int b) {
	visit[a][b] = 1;
	q.push({ a,b });
	tmp.push({ a,b });
	int sum = arr[a][b];
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) continue;
			if (visit[nx][ny]) continue;
			if (l <= abs(arr[nx][ny] - arr[x][y]) && abs(arr[nx][ny] - arr[x][y]) <= r) {
				visit[nx][ny] = 1;
				sum += arr[nx][ny];
				q.push({ nx,ny });
				tmp.push({ nx,ny });
				flag = true;
			}
		}
	}	

	int avr = sum / tmp.size();
	while (!tmp.empty()) {
		arr[tmp.front().first][tmp.front().second] = avr;
		tmp.pop();
	}
}

int main() {
	scanf("%d%d%d", &n, &l, &r);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);

	int cnt = 0;

	while (1) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				visit[i][j] = 0;

		flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visit[i][j]) {
					bfs(i, j);
				}
			}
		}
		if (!flag) break;
		cnt++;
	}
	printf("%d", cnt);
}

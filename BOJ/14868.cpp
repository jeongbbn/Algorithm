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

int n, k;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
queue<pi>q;
queue<pi>q1;

bool outrange(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>n - 1) return 1;
	return 0;
}
bool visit[2005][2005];
int arr[2005][2005];
int cnt;
vector<int>uf(100005, -1);
int find(int a) {
	if (uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y) return false;

	cnt++;
	if (uf[x] == uf[y]) uf[x]--;
	if (uf[x] < uf[y]) uf[y] = x;
	else uf[x] = y;
	return true;
}

void bfs(int size) {
	while (size--) {
		int x = q.front().first;
		int y = q.front().second;
		visit[x][y] = 1;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) continue;
			if (arr[nx][ny] == 0 && !visit[nx][ny]) {
				arr[nx][ny] = arr[x][y];
				q.push({ nx,ny });
				q1.push({ nx,ny });
				visit[nx][ny] = 1;
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr[a - 1][b - 1] = i;
		q.push({ a - 1,b - 1 });
	}

	int days = 0;
	while(1){
		if (cnt == k - 1) break;
		int size = q.size();
		bfs(size);
		isSame();
		days++;
	}
	printf("%d", days);
}


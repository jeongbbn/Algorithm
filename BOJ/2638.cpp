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
int arr[105][105];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
queue<pi>q;

bool outrange(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>m - 1) return 1;
	return 0;
}

void air(int a, int b) {
	int avisit[105][105] = { 0, };
	queue<pi>aq;
	avisit[0][0] = 1;
	arr[a][b] = -1;
	aq.push({ a,b });

	while (!aq.empty()) {
		int x = aq.front().first;
		int y = aq.front().second;
		aq.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) continue;
			if (avisit[nx][ny]) continue;

			if (arr[nx][ny] == 0) {
				arr[nx][ny] = -1;  aq.push({ nx,ny });
			} 
			else if (arr[nx][ny] == 4) q.push({ nx,ny });
			else aq.push({ nx,ny });
			avisit[nx][ny] = 1;
		}
	}
}

void cheese() {
	int size = q.size();
	while (size--) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) continue;
			if (arr[nx][ny] == -1) arr[x][y]--;
		}
		if (arr[x][y] < 3) arr[x][y] = 0;
		else arr[x][y] = 1;
	}
}

int main() {
	scanf("%d%d", &n,&m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);

	int days = 0;
	while (1) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (arr[i][j] == 1) { arr[i][j] = 4; }

		air(0, 0);

		if (q.empty()) { printf("%d", days); break; }
		cheese();
		days++;
	}
}

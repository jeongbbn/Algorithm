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
int arr[55][55];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
vector<pi>air;
queue<pi>q;
bool outrange(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>n - 1) return 1;
	return 0;
}
int vvisit[55][55] = { 0, };

void virus(int size) {
	while (size--) {
		int x = q.front().first;
		int y = q.front().second;
		vvisit[x][y] = 1;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) continue;
			if (vvisit[nx][ny]) continue;

			if (arr[nx][ny] != 1) {
				q.push({ nx,ny });
				vvisit[nx][ny] = 1;
			}
		}
	}
}

int count() {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!vvisit[i][j] && arr[i][j] == 0) cnt++;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			vvisit[i][j] = 0;

	return cnt;
}

bool ans[100];
int ans = INF, tmp;
bool flag;
void C(int idx, int k) {
	if (k == m) {
		for (int i = 0; i < air.size(); i++)
		{
			if (ans[i]) {
				q.push({ air[i].first,air[i].second });
				vvisit[air[i].first][air[i].second] = 1;
			};
		}
		int days = 0;

		while (1) {
			int size = q.size();
			virus(size);
			if (q.size() == 0) break;
			days++;
		}

		tmp = count();
		if (tmp == 0) { ans = min(ans, days); flag = true; }

		return;
	}

	for (int i = idx; i < air.size(); i++)
	{
		if (ans[i]) continue;
		ans[i] = 1;
		C(i, k + 1);
		ans[i] = 0;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) air.push_back({ i, j });
		}

	C(0, 0);
	if (!flag) ans = -1;
	printf("%d", ans);
}

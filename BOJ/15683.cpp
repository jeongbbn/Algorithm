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
int arr[15][15];
vector<pi>c;

bool outrange(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>m - 1) return 1;
	return 0;
}

int ans = INF;
int sel[10];

void up(int x, int y) {
	x--;
	while (!outrange(x, y) && arr[x][y] != 6) {
		if (arr[x][y] == 0) arr[x][y] = 8;
		x--;
	}
}
void down(int x, int y) {
	x++;
	while (!outrange(x, y) && arr[x][y] != 6) {
		if (arr[x][y] == 0) arr[x][y] = 8;
		x++;
	}
}
void right(int x, int y) {
	y++;
	while (!outrange(x, y) && arr[x][y] != 6) {
		if(arr[x][y]==0) arr[x][y] = 8;
		y++;
	}
}
void left(int x, int y) {
	y--;
	while (!outrange(x, y) && arr[x][y] != 6) {
		if (arr[x][y] == 0) arr[x][y] = 8;
		y--;
	}
}

int go() {
	for (int i = 0; i < c.size(); i++)
	{
		switch (arr[c[i].first][c[i].second]) {
		case 1:
			switch (sel[i]){
			case 1: right(c[i].first, c[i].second); break;
			case 2: 
				left(c[i].first, c[i].second); break;
			case 3:
				up(c[i].first, c[i].second); break;
			case 4:down(c[i].first, c[i].second); break;
			}
			break;
		case 2:
			switch (sel[i]) {
			case 1: 
				right(c[i].first, c[i].second); 
				left(c[i].first, c[i].second); break;
			case 2:
				up(c[i].first, c[i].second); 
				down(c[i].first, c[i].second);
				break;
			default: return INF;
			}
			break;
		case 3:
			switch (sel[i]) {
			case 1:
				right(c[i].first, c[i].second);
				up(c[i].first, c[i].second);
				break;
			case 2:
				left(c[i].first, c[i].second);
				up(c[i].first, c[i].second);
				break;
			case 3:
				left(c[i].first, c[i].second); 
				down(c[i].first, c[i].second); 
				break;

			case 4: 
				right(c[i].first, c[i].second);
				down(c[i].first, c[i].second);
				break;

			}
			break;
		case 4:
			switch (sel[i]) {
			case 1:
				right(c[i].first, c[i].second);
				up(c[i].first, c[i].second);
				left(c[i].first, c[i].second);
				break;
			case 2:
				left(c[i].first, c[i].second);
				down(c[i].first, c[i].second);
				right(c[i].first, c[i].second);
				break;

			case 3:
				up(c[i].first, c[i].second);
				down(c[i].first, c[i].second);
				right(c[i].first, c[i].second);
				break;

			case 4:
				up(c[i].first, c[i].second);
				down(c[i].first, c[i].second);
				left(c[i].first, c[i].second);
				break;
			default: return INF;
			}
			break;
		case 5:
			switch (sel[i]) {
			case 1:
				right(c[i].first, c[i].second);
				up(c[i].first, c[i].second);
				left(c[i].first, c[i].second);
				down(c[i].first, c[i].second);
				break;

			default: return INF;
			}
			break;
		}

	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 0) { cnt++; }

	return cnt;
}

void P(int k) {
	if (k == c.size()) {
		int tmp = go();
		ans = min(tmp, ans);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (arr[i][j] == 8) { arr[i][j] = 0; }
		return;
	}

	for (int i = 1; i <= 4; i++)
	{
		sel[k] = i;
		P(k + 1);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0 && arr[i][j] != 6) c.push_back({ i,j });
		}

	P(0);
	printf("%d", ans);
}

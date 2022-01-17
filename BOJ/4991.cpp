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

int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
int w, h;
int minans = INF;
int stX, stY;
vector<pi>keys;
char arr[25][25];
int mindist[25][25];

bool outrange(int x, int y) {
	if (x<0 || y<0 || x>h - 1 || y>w - 1) return 1;
	return 0;
}


/*
틀린 이유: 접근방식은 맞았으나, init()을 제대로 해주지 않았다.
minans=-1 경우에는 바로 return을 해주었는데,
이 때 check가 그대로여서 -1 이후 tc들은 INF가 나오게된다.
*/

long long startTo[15];
int ans[15];
bool check[15];

void P(int k) {
	if (k == keys.size()) {
		int sum = 0;
		int bfr = ans[0];
		sum += startTo[bfr];
		if (sum == INF) sum = -1;

		if (sum != -1) {
			for (int i = 1; i < keys.size(); i++)
			{
				if (mindist[bfr][ans[i]] == INF) { sum = -1; break; }
				sum += mindist[bfr][ans[i]];
				bfr = ans[i];
			}
		}
		
		minans = min(sum, minans);
		return;
	}

	for (int i = 0; i < keys.size(); i++)
	{
		if (check[i]) continue;
		ans[k] = i;
		check[i] = 1;
		P(k + 1);
		if (minans == -1) { return; } //틀린 이유
		check[i] = 0;
	}
}

void findMin() {
	for (int i = 0; i < keys.size(); i++)
	{
		bool tmpv[25][25] = { 0, };
		queue<pii>tmp;
		tmp.push({ 0, keys[i]});
		tmpv[keys[i].first][keys[i].second] = 1;

		while (!tmp.empty()) {
			int dist = tmp.front().first;
			int x = tmp.front().second.first;
			int y = tmp.front().second.second;
			tmp.pop();

			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (outrange(nx, ny)) continue;
				if (tmpv[nx][ny]) continue;
				if (arr[nx][ny] == 'x') continue;

				if (arr[nx][ny] == 'o') {
					startTo[i] = dist + 1;
				}
				if (arr[nx][ny] == '*') {
					int k = 0;
					for (k = 0; k < keys.size(); k++)
					{
						if (nx == keys[k].first && ny == keys[k].second)
							break;
					}
					mindist[i][k] = dist + 1;
					mindist[k][i] = dist + 1;
				}

				tmpv[nx][ny] = 1;
				tmp.push({ dist + 1,{nx,ny} });
			}
		}

	}
}

void init() {
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 25; j++)
			mindist[i][j] = INF;

	keys.clear();
	minans = INF;
	fill(startTo, startTo + 15, INF);
	fill(check, check + 15, 0);
	fill(ans, ans + 15, 0);
}

void put() {
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == 'o') {
				stX = i; stY = j;
			}
			else if (arr[i][j] == '*') {
				keys.push_back({ i,j });
			}
		}
	}
}
int main() {
	while (1) {
		scanf("%d%d", &w, &h);
		if (w == 0 && h == 0) return 0;

		init();
		put();

		findMin();
		P(0);
		printf("%d\n", minans);
	}
}


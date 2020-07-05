#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, limit = INF;
bool visit[2005][2005]; //1000+1000인 경우가 있을 수도 있으니까
queue<pii>q; 

void bfs(){
	while (!q.empty()) {
		int x = q.front().first;//현재 이모티콘 갯수
		int y = q.front().second.first; //클립보드에 있는 이모티콘의 수
		int cnt = q.front().second.second; //bfs 탐색 깊이
		q.pop();

		if (x == n) {
			printf("%d", cnt);
			return;
		}

		if (x > n) { //현재 이모티콘의 수가 n보다 큰 경우에는 -1 해주는 수 밖에 없음
			//그러므로 limit을 잡고, limit보다 커지지 않도록 관리
			limit = min(x, limit);
		}

		if (x + y < limit && !visit[x + y][y]) {
			q.push({ x + y,{y,cnt + 1} });
			visit[x + y][y] = 1;
		}

		if (!visit[x][x]) {
			q.push({ x,{x,cnt + 1} });
			visit[x][x] = 1;
		}

		if (x - 1 >= 0 && !visit[x - 1][y]) {
			q.push({ x - 1,{y,cnt + 1} });
			visit[x - 1][y] = 1;
		}
	}
}


int main() {
	scanf("%d", &n);
	q.push({ 1,{0, 0} });
	visit[1][0] = 1;
	bfs();
}

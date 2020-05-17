#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

typedef struct POS{
	int x;
	int y;
	bool operator< (POS a) {
		if (this->x == a.x) return this->y < a.y;
		return this->x < a.x; }
}pos;



/*
1. 연결되어있는지 확인 + 꼭짓점 좌표 따오기
2. 꼭짓점 좌표의 개수는 2 or 3이다.
(2인 경우는 ㄴ처럼 생긴 삼각형일 경우임)
3. 그래서 2인 경우에는 대각선으로 탐색해서 꼭짓점이 하나인 곳을 찾는다.
4. 
0000000000
0000001000
0000011000
0000111000
0001110000
0000111000
0000011000
0000001000
0000000000
0000000000
이렇게 된 경우를 찾기 위해, 
가로,세로,왼쪽대각선, 오른쪽대각선을 탐색하며
1234 4321인지 1357... 7531 인지 확인하고
하나라도 되는 경우가 있으면 삼각형이므로 답 출력 



*/
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };

int arr[15][15], cnt;
pos p[105];
int idx;
int row[15], column[15];
bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= 10 || y >= 10)return 1;
	return 0;
}

bool connect(int sx, int sy) {
	/*
	배열을 입력받으면서 세어준 1의 갯수와
	bfs를 돌면서 만나게 된 1의 갯수를 세어줘서 비교해준다.
	*/
	bool visit[15][15] = { 0, };
	queue<pi>q;
	visit[sx][sy] = 1;
	q.push({ sx,sy });

	int bfs = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int near = 0; //주변에 0이 세 개있으면, 그게 꼭짓점이다.
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) {near++; continue;}
			if (visit[nx][ny]) continue;
			if (arr[nx][ny] == 0) { near++; continue; }
			q.push({ nx,ny });
			visit[nx][ny] = 1;
			bfs++;
		}
		if (near == 3) {
			p[idx++] = { x,y };
		}

	}

	if (cnt == bfs) return 1;
	else return 0;
}

pair<int, pos> l[25], r[25];
int main() {
	int sx, sy;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%1d", &arr[i][j]);
			if (arr[i][j] == 1) { 
				sx = i; sy = j; cnt++; 

				l[i + j].first++;
				r[i - j + 9].first++;
				row[i]++;
				column[j]++;

				l[i + j].second.x = i;
				l[i + j].second.y = j;
				r[i - j + 9].second.x = i;
				r[i - j + 9].second.y = j;
			}
		}
	}

	if (!connect(sx, sy)) {
		printf("0"); return 0;
	}

	if (idx == 2) {
		pos tmp1, tmp2;
		int cnt1 =0 , cnt2= 0;
		for (int i = 0; i < 2*10-1; i++)
		{
			if (l[i].first == 1) { cnt1++; tmp1 = l[i].second; }
			if (r[i].first == 1) { cnt2++; tmp2 = r[i].second; }
		}

		if (cnt1 == 1) {
			p[idx++] = tmp1;
		}

		else if (cnt2 == 1) {
			p[idx++] = tmp2;
		}
	}

	if(idx != 3) { printf("0"); return 0; }

	bool a=0, b=0, c=0, d=0;
	bool e=0, f=0, j=0, k=0;
	for (int i = 0; i < 9; i++)
	{
		if (row[i]>0 && row[i+1] >0 && row[i]+2 > row[i+1]) a = 1;
		if (row[i]>0 && row[i+1] >0 && row[i] < row[i+1]+1) e = 1;
		if (column[i] > 0 && column[i + 1] > 0 && column[i]+2 > column[i + 1]) b = 1;
		if (column[i] > 0 && column[i + 1] > 0 && column[i] < column[i + 1]+2) f = 1;
	}

	for (int i = 0; i < 2*10-1; i++)
	{
		if (r[i].first > 0 && r[i + 1].first > 0 && r[i].first+1 > r[i + 1].first) c = 1;
		if (r[i].first > 0 && r[i + 1].first > 0 && r[i].first < r[i + 1].first+1) j = 1;
		if (l[i].first > 0 && l[i + 1].first > 0 && l[i].first+1 > l[i + 1].first) d = 1;
		if (l[i].first > 0 && l[i + 1].first > 0 && l[i].first < l[i + 1].first+1) k = 1;
	}

	if (a && b && c && d && e&&f &&j&&k) {
		printf("0"); return 0;
	}

	sort(p, p + idx);
	for (int i = 0; i < idx; i++)
	{
		printf("%d %d\n", p[i].x+1, p[i].y+1);
	}
	
}

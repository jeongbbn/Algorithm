#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int>pi;

int r, c, n, trial[105];
bool arr[105][105], connect[105][105];
queue<pi>q;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool outrange(int x, int y) {
	if (x <= 0 || y <= 0 || x > r || y > c) return 1;
	return 0;
}

//bfs를 돌면서 바닥과 연결되어있는 애들을 connect에 체크해준다.
void bfs(int sx, int sy) {
	q.push({ sx,sy });
	connect[sx][sy] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (outrange(nx, ny)) continue;
			if (connect[nx][ny]) continue;
			if (!arr[nx][ny])  continue;

			q.push({ nx,ny });
			connect[nx][ny] = 1;
		}
	}
}

//미네랄이 깨지고, 바뀌기 때문에
//매번 connect를 초기화 시켜줘야한다.
void init() {
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			connect[i][j] = 0;
}


//공중에 떠있는 미네랄을 떨어뜨려줌
void falling() {
	vector<pi>v;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			//미네랄이 있지만, 바닥과 연결되지 않은 애 == 공중에 떠 있는 애
			if (arr[i][j] && !connect[i][j]) {
				//v 배열에다가 담아주고, 그림(arr)에서 지워준다
				v.push_back({ i,j });
				arr[i][j] = 0;
			}
		}
	}

	//공중에 떠있는 클러스터가 없는 경우 함수 종료
	if (v.size() == 0) return;

	//만약 공중에 있는 클러스터 중 하나가 바닥이나 다른 클러스터 위(!!)에 닿은 경우
	bool isconnect = 0;
	while (1) {
		for (int i = 0; i < v.size(); i++)
		{
			int x = v[i].first;
			int y = v[i].second;
			
			//x==1이란 것은 결국 바닥에 도달했다는 뜻
			//connect[x-1][y]==1 이란 것은, 현재 x,y에서 아래칸을 봤을 때
			//아래에 바닥과 연결된 클러스터가 있다는 소리
			if (x == 1 || connect[x - 1][y]) isconnect = 1;
		}

		//만약 바닥에 닿거나, 바닥과 연결된 클러스터 위에 떨어진 경우
		if (isconnect) {
			//맵(arr를) 새로 그려준다.
			for (int i = 0; i < v.size(); i++) arr[v[i].first][v[i].second] = 1;
			break;
		}
		else {
			//아직 도달하지 못했으므로, 한 칸씩 내려준다.
			for (int i = 0; i < v.size(); i++) v[i].first--;
		}
	}
}

void func(int dir, int st, int height) {

	//connect배열을 매번 초기화 시켜줘야함
	init();

	//막대를 던진다
	for (int i = st; i <= c && i >= 1; i += dir)
	{
		if (arr[height][i]) {
			arr[height][i] = 0;
			break;
		}
	}

	//바닥에서 bfs 돌려서 바닥과 연결된 애들을 체크해준다.
	for (int i = 1; i <= c; i++)
	{
		if (!arr[1][i]) continue;
		if (connect[1][i]) continue;
		bfs(1, i);
	}
	
	falling();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	
	//편의상 (int i = r; i >= 1; i--) 이렇게 받아줌
	for (int i = r; i >= 1; i--) {
		for (int j = 1; j <= c; j++) {
			char c; cin >> c;
			if (c == 'x') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> trial[i];

	for (int i = 1; i <= n; i++)
	{
		//홀수면 왼쪽에서 던짐
		int dir = 1, st = 1;

		//짝수면 오른쪽에서 던짐
		if (i % 2 == 0) { dir = -1; st = c; }
		func(dir, st, trial[i]);
	}

	for (int i = r; i >= 1; i--) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j]) cout << 'x';
			else cout << '.';
		}
		cout << "\n";
	}
}

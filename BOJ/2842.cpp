#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pi;
#define INF 1e9

/*
	problem : 
	1) 왔던 곳을 다시 방문하면 안된다는 조건이 없기 때문에, 왔던 길 그대로 돌아갈 수 있다.
	2) 자신이 갔던 길 중 고도가 가장 높은 곳 - 고도가 가장 낮은 곳 하면 된다.
	3) MAP에 있는 고도 범위 안에서 결정되기 때문에, v에 대해서 투 포인터를 사용하면 된다.
	4) 투 포인터에서 st(1)~en(9)이 가능하다면 st를 올려줘야한다.
	st(2)~en(9) 이런 식으로 좁혀나가면서 고도 차이의 최솟값을 구하면 된다.
	-> st(3)~en(5)는 왜 안보는가? 만약 st(3)~en(5)가 된다면, st(1)~en(5)에서 당연히 돼서
	en(9)까지 가지않고, en(5)에서 멈췄어야했다.

	5) bfs는 안되나 싶지만, 마치 조합처럼 P에서 갈 수 있는 곳들을 체크해두고
	얘네들에 대해서 길이 알아서 생긴다고 생각하면 편하다.

	algo : 투포인터, bfs
*/

int dx[] = { 0,0,1,-1,-1,-1,1,1 };
int dy[] = { -1,1,0,0,-1,1,-1,1 };

int n, sx, sy, cntK, ans = INF, maxx;
vector<string>arr;
vector<int>v;
int MAP[55][55];

bool bfs(int st, int en) {
	queue<pi>q;
	bool visited[55][55] = { 0, };
	q.push({ sx,sy });
	visited[sx][sy] = 1;
	if (st > MAP[sx][sy] || en < MAP[sx][sy]) return 0;

	int flag = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny]) continue;
			if (st > MAP[nx][ny] || en < MAP[nx][ny]) continue;
			if (arr[nx][ny] == 'K') flag++;
			q.push({ nx,ny });
			visited[nx][ny] = 1;
		}
	}

	if (flag == cntK) return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 'P') {
				sx = i; sy = j;
			}
			else if (arr[i][j] == 'K') cntK++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
			v.push_back(MAP[i][j]);
		}
	}

	sort(v.begin(), v.end());

	int st = 0, en = 0;
	while (st <= en && en < v.size()) {
		if (bfs(v[st], v[en])) {
			ans = min(v[en] - v[st], ans);
			st++;
		}
		else en++;
	}
	cout << ans;
}

/*
2
P.
.K
1 5
5 5

2
P.
.K
3 1
1 5
*/

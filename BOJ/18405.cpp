#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int n, k,s ,x,y;
int arr[205][205];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<pi>q;
vector<pii>v;

bool outrange(int x, int y) {
	if (x <= 0 || y <= 0 || x > n || y > n) return 1;
	return 0;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0) {
				v.push_back({ arr[i][j] , { i,j }});
			}
		}
	}
	scanf("%d%d%d", &s, &x, &y);

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		q.push({ v[i].second.first,v[i].second.second });
	}

	while (s--) {
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
				if (arr[nx][ny] != 0) continue;
				arr[nx][ny] = arr[x][y];
				q.push({ nx,ny });
			}
		}
	}
	printf("%d", arr[x][y]);
}

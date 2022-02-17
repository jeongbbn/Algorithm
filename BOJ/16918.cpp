#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int r, c, n;
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
int timetable[205][205];

/*
1 4 5
...O
...O인데, 예외처리를 제대로 안하면
..OO이 된다.
*/

int main() {
	scanf("%d%d%d", &r, &c, &n);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			char a;
			scanf(" %c", &a);
			if (a == 'O') timetable[i][j] = 0;
			else timetable[i][j] = -1;
		}
	}

	for (int t = 2; t <= n; t++)
	{
		for (int x = 0; x < r; x++)
		{
			for (int y = 0; y < c; y++)
			{
				if (timetable[x][y] >= 0 && timetable[x][y] + 3 == t) {
					for (int i = 0; i < 4; i++)
					{
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
						if (timetable[x][y] == timetable[nx][ny]) continue;
						timetable[nx][ny] = -2;
					}
					timetable[x][y] = -2;
				}
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (timetable[i][j] == -1) timetable[i][j] = t;
				else if (timetable[i][j] == -2) timetable[i][j]++;
			}
		}

	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (timetable[i][j] < 0) printf(".");
			else printf("O");
		}
		printf("\n");
	}
}

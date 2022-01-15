#include <iostream>
#include <queue>

using namespace std;

int w, h, cnt;
bool flag;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

char map[1005][1005];

bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x > h - 1 || y > w - 1) return 1;
	return 0;
}

int main() {
	int t;
	scanf("%d", &t);

	for (int l = 0; l < t; l++)
	{
		cnt = 0;
		flag = false;
		queue<pair<int, int>>fq;
		queue<pair<int, int>>hq;

		scanf("%d %d", &w, &h);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				scanf(" %c", &map[i][j]);
				if (map[i][j] == '*')
					fq.push({ i,j });
				else if (map[i][j] == '@')
					hq.push({ i,j });
			}

		while (!hq.empty()) {
			cnt++;
			//fire
			int size = fq.size();
			while (size != 0) {
				int x = fq.front().first;
				int y = fq.front().second;
				fq.pop();
				for (int i = 0; i < 4; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (outrange(nx, ny)) continue;
					if (map[nx][ny] == '.' || map[nx][ny] == '@') {
						map[nx][ny] = '*';
						fq.push({ nx,ny });
					}
				}
				size--;
			}

			//human
			size = hq.size();
			while (size != 0) {
				int x = hq.front().first;
				int y = hq.front().second;
				hq.pop();
				for (int i = 0; i < 4; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (outrange(nx,ny)) {
						flag = true;
						break; 
					}
					if (map[nx][ny] == '.') {
						map[nx][ny] = '@';
						hq.push({ nx,ny });
					}
				}
				size--;
				if (flag == true) break;
				//탈출했으므로, 굳이 큐에 남은 것들을 확인할 필요 없음
			}
			if (flag == true) break; //전체 while문 탈출
		}
		if (flag == false)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",cnt);
	}
}

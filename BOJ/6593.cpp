#include <iostream>
#include <queue>
using namespace std;

struct pos {
	int x;
	int y;
	int z;
	int dist;
};

int l, r, c;
int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
queue<pos>q;
int check[35][35][35];
char arr[35][35][35];

bool inrange(int x, int y, int z) {
	if (x < 0 || x >= c || y < 0 || y >= r || z < 0 || z >= l) return 0;
	else return 1;
}

void bfs() {
	while (!q.empty()) {
		pos s = q.front();
		q.pop();

		if (arr[s.z][s.y][s.x] == 'E') {
			printf("Escaped in %d minute(s).\n", s.dist);
			while (!q.empty()) q.pop();
			return;
		}

		for (int i = 0; i < 6; i++)
		{
			int newx = s.x + dx[i];
			int newy = s.y + dy[i];
			int newz = s.z + dz[i];
			int dist = s.dist;

			if (!inrange(newx, newy, newz)) continue;
			if (arr[newz][newy][newx] == '#') continue;
			if (check[newz][newy][newx] == 1) continue;
			check[newz][newy][newx] = 1;
			q.push({ newx,newy,newz,dist+1 });
		}
	}
	printf("Trapped!\n");
}

int main() {

	while (1) {	
		for (int i = 0; i < 35; i++)
			for (int j = 0; j < 35; j++)
				for (int k = 0; k < 35; k++) {
					check[i][j][k] = 0;
					arr[i][j][k] = '\0';
				}

		scanf("%d%d%d", &l, &r, &c);

		if (l == 0 && r == 0 && c == 0) return 0;

		for (int i = 0; i < l; i++)
			for (int j = 0; j < r; j++)
				for (int k = 0; k < c; k++)
				{
					scanf(" %c", &arr[i][j][k]);
					if (arr[i][j][k] == 'S') { q.push({ k,j,i, 0 }); check[i][j][k] = 1;}
				}

		bfs();

	}
}

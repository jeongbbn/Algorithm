#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define INF 1e9;

int n, q;
bool visit[3][200005];
bool slash[200005];
bool backslash[200005];
bool row[200005];
int scnt, bscnt, rcnt;

bool outrange(int x, int y) {
	if (x < 1 || y < 1 || x > 2 || y > n) return 1;
	return 0;
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < q; i++)
	{
		int r, c;
		scanf("%d%d", &r, &c);

		visit[r][c] = !visit[r][c];

		if (visit[r][c]) {
			//오른쪽 아래
			if (!outrange(r + 1, c + 1) && visit[r + 1][c + 1]) { 
				if (!backslash[r - c + n - 1]) { backslash[r - c + n - 1] = 1; bscnt++; }
			}

			//오른쪽 위
			if (!outrange(r - 1, c + 1) && visit[r - 1][c + 1]) {
				if (!slash[r + c]) { slash[r + c] = 1; scnt++; }
			}

			//왼쪽 아래
			if (!outrange(r + 1, c - 1) && visit[r + 1][c - 1]) {
				if (!slash[r + c]) { slash[r + c] = 1; scnt++; }
			}

			//왼쪽 위
			if (!outrange(r - 1, c - 1) && visit[r - 1][c - 1]) { 
				if (!backslash[r - c + n - 1]) { backslash[r - c + n - 1] = 1; bscnt++; }
				}

			//같은 행 아래
			if (!outrange(r + 1, c) && visit[r + 1][c]) { 
				if(!row[c]) { row[c] = 1; rcnt++; }
				}

			//같은 행 위
			if (!outrange(r - 1, c) && visit[r - 1][c]) { 
				if (!row[c]) { row[c] = 1; rcnt++; }
				}

			if (rcnt == 0 && scnt == 0 && bscnt == 0)	printf("Yes\n");
			else printf("No\n");
		}
		else{
			//오른쪽 아래
			if (!outrange(r + 1, c + 1) && visit[r + 1][c + 1]) {
				if (backslash[r - c + n - 1]) { backslash[r - c + n - 1] = 0; bscnt--; }

			}

			//오른쪽 위
			if (!outrange(r - 1, c + 1) && visit[r - 1][c + 1]) {
				if (slash[r + c]) { slash[r + c] = 0; scnt--; }
			}

			//왼쪽 아래
			if (!outrange(r + 1, c - 1) && visit[r + 1][c - 1]) {
				if (slash[r + c]) { slash[r + c] = 0; scnt--; }
			}

			//왼쪽 위
			if (!outrange(r - 1, c - 1) && visit[r - 1][c - 1]) {
				if (backslash[r - c + n - 1]) { backslash[r - c + n - 1] = 0; bscnt--; }
			}

			//같은 행 아래
			if (!outrange(r + 1, c) && visit[r + 1][c]) {
				if (row[c]) { row[c] = 0; rcnt--; }
			}

			//같은 행 위
			if (!outrange(r - 1, c) && visit[r - 1][c]) {
				if (row[c]) { row[c] = 0; rcnt--; }
			}

			if(rcnt == 0 && scnt == 0 && bscnt == 0)	printf("Yes\n");
			else printf("No\n");
		}
	}
}

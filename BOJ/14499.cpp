#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

typedef struct{
	int top;
	int bottom;
	int leftt;
	int rightt;
	int front;
	int back;
} dice;

dice d = { 0,0,0,0,0,0 };
int n, m, x, y, k;
int arr[25][25];

void roll(int dir) {
	//동
	if (dir == 1) {
		int tmp1 = d.top;
		int tmp2 = d.rightt;
		d.rightt = tmp1;

		tmp1 = tmp2;
		tmp2 = d.bottom;
		d.bottom = tmp1;

		tmp1 = tmp2;
		tmp2 = d.leftt;
		d.leftt = tmp1;

		tmp1 = tmp2;
		d.top = tmp1;
	}
	//서
	else if (dir == 2) {
		int tmp1 = d.top;
		int tmp2 = d.leftt;
		d.leftt = tmp1;

		tmp1 = tmp2;
		tmp2 = d.bottom;
		d.bottom = tmp1;

		tmp1 = tmp2;
		tmp2 = d.rightt;
		d.rightt = tmp1;

		tmp1 = tmp2;
		d.top = tmp1;
	}
	//북
	else if (dir == 3) {
		int tmp1 = d.top;
		int tmp2 = d.back;
		d.back = tmp1;

		tmp1 = tmp2;
		tmp2 = d.bottom;
		d.bottom = tmp1;

		tmp1 = tmp2;
		tmp2 = d.front;
		d.front = tmp1;

		tmp1 = tmp2;
		d.top = tmp1;
	}
	//남
	else {
		int tmp1 = d.top;
		int tmp2 = d.front;
		d.front = tmp1;
		
		tmp1 = tmp2;
		tmp2 = d.bottom;
		d.bottom = tmp1;

		tmp1 = tmp2;
		tmp2 = d.back;
		d.back = tmp1;

		tmp1 = tmp2;
		d.top = tmp1;
	}
}

bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return 1;
	return 0;
}

int main() {
	scanf("%d%d%d%d%d", &n, &m, &x, &y, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);

	for (int i = 0; i < k; i++) {
		int a;
		scanf("%d", &a);

		//동
		if (a == 1) {
			if (outrange(x, y + 1)) continue;
			roll(1);
			y++;
		}
		//서
		else if (a == 2) {
			if (outrange(x, y - 1)) continue;
			roll(2);
			y--;
		}
		//북
		else if (a == 3) {
			if (outrange(x - 1, y)) continue;
			roll(3);
			x--;
		}
		//남
		else {
			if (outrange(x + 1, y)) continue;
			roll(4);
			x++;
		}

		if (arr[x][y] == 0) arr[x][y] = d.bottom;
		else {
			d.bottom = arr[x][y];
			arr[x][y] = 0;
		}
		printf("%d\n", d.top);
	}
}

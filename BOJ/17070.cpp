#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int arr[20][20];
int n, cnt;

bool outrange(int x, int y) {
	if (x <= 0 || y <= 0 || x >= n + 1 || y >= n + 1) return 1;
	return 0;
}

void dfs(int flag, int dx, int dy) {

	if (dx == n && dy == n) {
		cnt++;
		return;
	}
	if (outrange(dx, dy)) return ;

	if (flag == 0) {

		if (arr[dx][dy + 1] != 1) dfs(0, dx, dy + 1);

		if (arr[dx + 1][dy + 1] != 1 && arr[dx][dy + 1] != 1 && arr[dx + 1][dy] != 1)
			dfs(2, dx + 1, dy + 1);
	}

	else if (flag == 1) {
		if (arr[dx + 1][dy] != 1)
			dfs(1, dx + 1, dy);

		if (arr[dx + 1][dy + 1] != 1 && arr[dx][dy + 1] != 1 && arr[dx + 1][dy] != 1)
			dfs(2, dx + 1, dy + 1);
	}

	else {
		if (arr[dx][dy + 1] != 1)
			dfs(0, dx, dy + 1);

		if (arr[dx + 1][dy] != 1)
			dfs(1, dx + 1, dy);

		if (arr[dx + 1][dy + 1] != 1 && arr[dx][dy + 1] != 1 && arr[dx + 1][dy] != 1)
			dfs(2, dx + 1, dy + 1);
	}

}


int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}

	dfs(0, 1, 2);

	printf("%d", cnt);
}

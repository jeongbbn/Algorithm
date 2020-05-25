#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, m;
int arr[505][505];
int maxx;

bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return 1;
	return 0;
}

int nemo(int x, int y) {
	int sum = 0;
	if (outrange(x + 1, y + 1)) return -1;
	for (int i = x; i < x + 2; i++)
		for (int j = y; j < y + 2; j++)
			sum += arr[i][j];

	return sum;
}

void giyuk(int x, int y, int nemo) {
	if (!outrange(x - 1, y))
		maxx = max(maxx, nemo - arr[x][y + 1] + arr[x - 1][y]);

	if (!outrange(x - 1, y + 1))
		maxx = max(maxx, nemo - arr[x][y] + arr[x - 1][y + 1]);

	if (!outrange(x + 2, y + 1))
		maxx = max(maxx, nemo - arr[x + 1][y] + arr[x + 2][y + 1]);

	if (!outrange(x + 2, y))
		maxx = max(maxx, nemo - arr[x + 1][y + 1] + arr[x + 2][y]);

	if (!outrange(x, y - 1))
		maxx = max(maxx, nemo - arr[x + 1][y] + arr[x][y - 1]);

	if (!outrange(x, y + 2))
		maxx = max(maxx, nemo - arr[x + 1][y + 1] + arr[x][y + 2]);

	if (!outrange(x + 1, y - 1))
		maxx = max(maxx, nemo - arr[x][y] + arr[x + 1][y - 1]);

	if (!outrange(x + 1, y + 2))
		maxx = max(maxx, nemo - arr[x][y + 1] + arr[x + 1][y + 2]);

}

void san(int x, int y, int nemo) {

	if (!outrange(x, y - 1))
		maxx = max(maxx, nemo - arr[x + 1][y + 1] + arr[x][y - 1]);

	if (!outrange(x + 1, y - 1))
		maxx = max(maxx, nemo - arr[x][y + 1] + arr[x + 1][y - 1]);

	if (!outrange(x - 1, y))
		maxx = max(maxx, nemo - arr[x + 1][y + 1] + arr[x - 1][y]);

	if (!outrange(x - 1, y + 1))
		maxx = max(maxx, nemo - arr[x + 1][y] + arr[x - 1][y + 1]);

}

void rieul(int x, int y, int nemo) {

	if (!outrange(x - 1, y))
		maxx = max(maxx, nemo - arr[x + 1][y] + arr[x - 1][y]);

	if (!outrange(x - 1, y + 1))
		maxx = max(maxx, nemo - arr[x + 1][y + 1] + arr[x - 1][y + 1]);

	if (!outrange(x + 1, y - 1))
		maxx = max(maxx, nemo - arr[x + 1][y + 1] + arr[x + 1][y - 1]);

	if (!outrange(x + 1, y + 2))
		maxx = max(maxx, nemo - arr[x + 1][y] + arr[x + 1][y + 2]);

}

void giljjuk(int x, int y, int nemo) {

	if (!outrange(x + 2, y) && !outrange(x + 3, y))
		maxx = max(maxx, nemo - arr[x][y + 1] - arr[x + 1][y + 1] + arr[x + 2][y] + arr[x + 3][y]);

	if (!outrange(x + 2, y + 1) && !outrange(x + 3, y + 1))
		maxx = max(maxx, nemo - arr[x][y] - arr[x + 1][y] + arr[x + 2][y + 1] + arr[x + 3][y + 1]);

	if (!outrange(x, y + 2) && !outrange(x, y + 3))
		maxx = max(maxx, nemo - arr[x + 1][y] - arr[x + 1][y + 1] + arr[x][y + 2] + arr[x][y + 3]);

	if (!outrange(x + 1, y + 2) && !outrange(x + 1, y + 3))
		maxx = max(maxx, nemo - arr[x][y] - arr[x][y + 1] + arr[x + 1][y + 2] + arr[x + 1][y + 3]);


}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = nemo(i, j);
			maxx = max(maxx, x);

			giyuk(i, j, x);
			san(i, j, x);
			rieul(i, j, x);
			giljjuk(i, j, x);
		}
	}

	printf("%d", maxx);
}

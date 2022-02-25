#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

int n, m, t, arr[55][55], x, d, k, ans;

void func(int st, int diff, int step) {
	for (int tc = 0; tc < k; tc++)
	{
		int tmp = arr[step][st];
		for (int i = st + diff; i <= m && i >= 1; i += diff)
		{
			int tmp2 = arr[step][i];
			arr[step][i] = tmp;
			tmp = tmp2;
		}
		arr[step][st] = tmp;
	}
}

bool isSame(int x1, int y1, int x2, int y2, bool visited[][55]) {
	if (arr[x1][y1] == arr[x2][y2]) {
		visited[x1][y1] = 1;
		visited[x2][y2] = 1;
		return 1;
	}
	return 0;
}

void near() {
	int sum = 0, cnt = 0;

	bool visited[55][55] = { 0, };
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (visited[i][j]) continue;
			if (arr[i][j] == 0) continue;

			//����
			isSame(i, j, i - 1, j, visited);
			isSame(i, j, i + 1, j, visited);

			//����
			if (j == 1) isSame(i, j, i, m, visited);
			else isSame(i, j, i, j - 1, visited);

			if (j == m) isSame(i, j, i, 1, visited);
			else isSame(i, j, i, j + 1, visited);
		}
	}

	bool flag = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (visited[i][j]) {
				arr[i][j] = 0; flag = 1;
			}
			else {
				if (arr[i][j] == 0) continue;
				cnt++; sum += arr[i][j];
			}
		}
	}

	if (!flag) {
		if (cnt == 0) return;
		int avg = sum / cnt;
		bool digit = sum % cnt;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (visited[i][j]) continue;
				if (arr[i][j] == 0) continue;

				if (arr[i][j] > avg) arr[i][j]--;
				else if (arr[i][j] == avg) {
					if (digit) arr[i][j]++;
				}
				else arr[i][j]++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	for (int i = 0; i < t; i++)
	{
		cin >> x >> d >> k;
		for (int step = 1; step <= n; step++)
		{
			if (step % x == 0) {
				if (d == 0) func(1, 1, step);
				else func(m, -1, step);
			}
		}
		near();
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans += arr[i][j];

	cout << ans;
}

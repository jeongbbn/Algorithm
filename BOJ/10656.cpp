#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int>pi;

int n, m;
char arr[55][55];
vector<pi>ans;

bool outrange(int x, int y) {
	if (x <= 0 || y <= 0 || x > n || y > m) return 1;
	return 0;
}

bool func(int x, int y, bool f) {
	if (f == 1) {
		if (!outrange(x, y - 1) && arr[x][y - 1] != '#') return 0;
		for (int k = 1; k < 3; k++)
		{
			if (outrange(x, y + k)) return 0;
			if (arr[x][y + k] == '#') return 0;
		}
		return 1;
	}
	else {
		if (!outrange(x - 1, y) && arr[x - 1][y] != '#') return 0;
		for (int k = 1; k < 3; k++)
		{
			if (outrange(x + k, y)) return 0;
			if (arr[x + k][y] == '#') return 0;
		}
		return 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] == '#') continue;

			bool flag = func(i, j, 1);
			flag = max(flag, func(i, j, 0));

			if (flag) ans.push_back({ i,j });
		}
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
}


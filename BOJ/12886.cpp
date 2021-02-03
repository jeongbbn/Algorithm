#include<bits/stdc++.h>
using namespace std;

vector<int> v;
bool dp[505][505][505], ans;

vector<int> func(int a, int b, int c, vector<int>arr) {
	vector<int>tmp;
	tmp.resize(3);
	tmp[a] = arr[a] * 2;
	tmp[b] = arr[b] - arr[a];
	tmp[c] = arr[c];
	return tmp;
}

void dfs(vector<int>arr) {
	sort(arr.begin(), arr.end());

	if (arr[0] == arr[1] && arr[1] == arr[2]) {
		ans = 1;
		return;
	}

	if (dp[arr[0]][arr[1]][arr[2]]) return;
	dp[arr[0]][arr[1]][arr[2]] = 1;

	dfs(func(0, 1, 2, arr));
	dfs(func(1, 2, 0, arr));
	dfs(func(0, 2, 1, arr));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	v.resize(3);
	cin >> v[0] >> v[1] >> v[2];
	dfs(v);
	cout << ans;
}

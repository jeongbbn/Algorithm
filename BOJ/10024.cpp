#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

int n, arr[105], bpos[105], apos[105], sizee, len;

void dfs(int x, int cnt) {
	if (bpos[x] == apos[x]) {
		len = max(cnt, len);
		return;
	}

	int now = apos[x], target = bpos[x];
	swap(arr[target], arr[now]);
	swap(apos[arr[now]], apos[arr[target]]);
	dfs(arr[now], cnt + 1);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		apos[arr[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		bpos[x] = i;
	}

	for (int i = 0; i < n; i++)
	{
		if (apos[arr[i]] == bpos[arr[i]]) continue;
		dfs(arr[i], 1);
		sizee++;
	}

	if (len == 0) len = -1;
	cout << sizee << " " << len;
}

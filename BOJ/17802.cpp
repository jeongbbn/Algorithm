#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1987654321
typedef pair<string, bool>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, m, q;
vector<int>l, r, arr, good, tree;
bool over;

int init(int node, int st, int en) {
	if (st == en) {
		if (good[st] > 0) tree[node] = arr[st];
		else tree[node] = -MAX;
		return tree[node];
	}
	int mid = (st + en) / 2;
	tree[node] = max(init(2 * node, st, mid), init(2 * node + 1, mid + 1, en));
	return tree[node];
}

int update(int node, int st, int en, int idx, int diff) {
	if (idx < st || en < idx) return tree[node];
	if (st == en) {
		tree[node] = diff;
		return tree[node];
	}
	int mid = (st + en) / 2;
	tree[node] = max(update(node * 2, st, mid, idx, diff), update(node * 2 + 1, mid + 1, en, idx, diff));
	return tree[node];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> q;

	arr.resize(n + 1);
	good.resize(n + 2);
	tree.resize(4 * n + 1);
	l.resize(m);
	r.resize(m);

	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 0; i < m; i++) cin >> l[i];
	for (int i = 0; i < m; i++) cin >> r[i];

	sort(l.begin(), l.end());
	sort(r.begin(), r.end());

	//find range
	for (int i = 0; i < m; i++)
	{
		if (l[i] > r[i]) {
			over = 1;
			continue;
		}
		good[l[i]]++;
		good[r[i] + 1]--;
	}

	for (int i = 2; i <= n; i++) good[i] += good[i - 1];

	//segment
	init(1, 1, n);

	while (q--) {
		int a, b;
		cin >> a >> b;

		if (good[a] > 0 && good[b] > 0) {
			update(1, 1, n, a, arr[b]);
			update(1, 1, n, b, arr[a]);
		}
		else if (good[a] > 0 && good[b] == 0) {
			update(1, 1, n, a, arr[b]);
		}
		else if (good[b] > 0 && good[a] == 0) {
			update(1, 1, n, b, arr[a]);
		}

		swap(arr[a], arr[b]);

		if (over) cout << 1000000000 << "\n";
		else cout << tree[1] << "\n";
	}
}

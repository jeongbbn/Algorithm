#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
#define END 2'000'001
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<pi, int>pii;

int n;
int tree[8'000'005];

void insert(int node, int st, int en, int idx) {
	if (idx < st || en < idx) return;
	tree[node]++;
	if (st != en) {
		int mid = (st + en) / 2;
		insert(node * 2, st, mid, idx);
		insert(node * 2 + 1, mid + 1, en, idx);
	}
}

int remove(int node, int st, int en, int sum) {
	tree[node]--;
	if (st == en) return st;
	int mid = (st + en) / 2;
	if (tree[2 * node] >= sum) return remove(node * 2, st, mid, sum);
	else return remove(node * 2 + 1, mid + 1, en, sum - tree[2 * node]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while(n--){
		int t, x;
		cin >> t >> x;
		if (t == 1) insert(1, 0, END, x);
		else cout << remove(1, 0, END, x) << "\n";
	}
}

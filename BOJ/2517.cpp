#include<bits/stdc++.h>
using namespace std;

/*
	세그먼트 트리의 인덱스에 배치를 해두고, 값으로는 개수(1)을 넣어주어
	구간 합을 이용하여 자신의 왼쪽에 몇 명있는지를 세어준다.

	하지만 각 정수는 1 이상 1,000,000,000 이하이므로, arr[1,000,000,000]가 안된다.
	따라서 map을 이용하여, 라벨링을 해주고 arr[500,000]으로 설정하여
	세그먼트 트리를 만들어준다.
*/

int n;
vector<int>arr;
priority_queue<int, vector<int>, greater<int>> pq;
map<int, int>m;
int tree[2000005];

void update(int node, int st, int en, int idx) {
	if (idx < st || en < idx) return;
	tree[node] += 1;
	if (st != en) {
		int mid = (st + en) / 2;
		update(node * 2, st, mid, idx);
		update(node * 2 + 1, mid + 1, en, idx);
	}
}

int sum(int node, int st, int en, int l, int r) {
	if (en < l || r < st) return 0;
	if (l <= st && en <= r) return tree[node];
	int mid = (st + en) / 2;
	return sum(node * 2, st, mid, l, r) + sum(node * 2 + 1, mid + 1, en, l, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		arr.push_back(a);
		pq.push(a);
	}

	int idx = 0;
	while (!pq.empty()) {
		m[pq.top()] = idx++;
		pq.pop();
	}

	for (int i = 0; i < arr.size(); i++)
	{
		int x = m[arr[i]];
		cout << (i+1) - sum(1, 0, n - 1, 0, x) << "\n";
		update(1, 0, n - 1, x);
	}
}

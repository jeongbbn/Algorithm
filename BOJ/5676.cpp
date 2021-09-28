#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> pii;
using ti = tuple<int, int, int>;

int arr[100001];
int tree[400005];

int n, k;
int init(int node, int st, int en) {
	if (st == en) return tree[node] = arr[st]; 
	else {
		int mid = (st + en) / 2;
		return tree[node] = init(node * 2, st, mid) * init(node * 2 + 1, mid + 1, en);
	}
}

int update(int node, int st, int en, int idx, int diff) {
	if(idx < st || en < idx) return tree[node];
	if(st == en){
		return tree[node] = diff;
	}
	if (st != en) {
		int mid = (st + en) / 2;
		return tree[node] = update(node * 2, st, mid, idx, diff) * update(node * 2 + 1, mid + 1, en, idx, diff);
	}
}

int find(int node, int l, int r, int st, int en) {
	if (r < st || l > en) return 1;
	if (l <= st && en <= r) return tree[node];
	int mid = (st + en) / 2;
	return find(node * 2, l, r, st, mid) * find(node * 2 + 1, l, r, mid + 1, en);
}

int main() {

	while (scanf("%d%d", &n, &k) != EOF) {

		vector<char>ans;

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
			if (arr[i] > 0) arr[i] = 1;
			else if (arr[i] == 0) arr[i] = 0;
			else arr[i] = -1;
		}

		init(1, 0, n-1);

		for (int i = 0; i < k; i++)
		{
			char a;
			int b, c;
			scanf(" %c%d%d", &a, &b, &c);

			if (a == 'C') {
				if (c > 0) c = 1;
				else if (c == 0) c = 0;
				else c = -1;

				if (c == arr[b - 1]) continue;
				update(1, 0, n - 1, b - 1, c);
				arr[b-1] = c;
			}

			else {
				int tmp = find(1, b - 1, c - 1, 0, n - 1);
				if (tmp > 0) ans.push_back('+');
				else if (tmp == 0) ans.push_back('0');
				else ans.push_back('-');
			}
		}
		for (int i = 0; i < ans.size(); i++)
		{
			printf("%c", ans[i]);
		}
		printf("\n");
	}


}

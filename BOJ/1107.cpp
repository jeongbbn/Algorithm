#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int n, m, len = 1;
bool check[10];
int key[7];
int minn;
bool zero;
vector<int>help;

void dfs(int k, int l) {
	if (k == l) {
		int digit = 1;
		int sum = 0, idx = k-1;
		while (l--) {
			sum += (digit * key[idx--]);
			digit *= 10;
		}

		if (sum == 0) { zero = 1; k = 1; }

		int diff = 0;
		if (sum > n) {
			diff = sum - n + k;
		}
		else {
			diff = n - sum + k;
		}

		minn = min(minn, diff);

		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (check[i]) continue;
		if (zero && k == 0 && i == 0) continue;
		key[k] = i;
		dfs(k + 1, l);
	}
}

int main() {
	scanf("%d%d", &n,&m);

	int tmp = n;

	while (tmp/=10) {
		len++;
	}

	for (int i = 0; i < m; i++)
	{
		int a;
		scanf("%d", &a);
		check[a] = 1;
	}
	
	if (100 > n) {
		minn = 100 - n;
	}
	else {
		minn = n - 100;
	}

	dfs(0, len);
	if(len != 6) dfs(0, len+1);
	if(len != 1) dfs(0, len-1);

	printf("%d", minn);
}

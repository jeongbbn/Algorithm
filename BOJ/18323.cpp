#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, m, sum;
int b[1005];
bool chk[10005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
		scanf("%d", &b[i]);
	
	vector<int>ans;
	for (int x = 1; x < b[0]; x++)
	{
		fill(chk, chk + n + 1, 0);
		ans.clear();
		ans.push_back(x);
		int y = b[0] - x;
		chk[x] = 1;
		int i = 1;
		for (; i < n - 1; i++) {
			if (b[i] <= y) break;
			if (chk[y]) break;
			ans.push_back(y);
			chk[y] = 1;
			y = b[i] - y;
		}
		if (i == n - 1) {
			if (!chk[y]) ans.push_back(y);
		}
		if (n == ans.size()) break;
	}


	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}
}

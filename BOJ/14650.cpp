#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef long long ll;
typedef pair<ll, ll>pi;
typedef pair<int, pair<int, int>>pii;

int n, ans;

void dfs(int k, string s) {
	if (k == n) {
		if (s[0] == '0') return;
		int tmp = stoi(s);
		if (tmp % 3 == 0) ans++;
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		dfs(k + 1, s + to_string(i));
	}
}
int main() {
	scanf("%d", &n);
	dfs(0,"");
	printf("%d", ans);
}

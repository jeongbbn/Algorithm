#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int n, ans;
string str;
int dp[1505][1505];

int func(int st, int en, int cnt, char c) {
	if (st > en) return cnt;
	if (dp[st][en] != 0) return dp[st][en];

	dp[st][en] = cnt;
	if (c == 'B') {
		if (str[st] == 'L') dp[st][en] = max(dp[st][en], func(st + 1, en, cnt + 1, str[st]));
		if (str[en] == 'L') dp[st][en] = max(dp[st][en], func(st, en - 1, cnt + 1, str[en]));
	}
	else if (c == 'L') {
		if (str[st] == 'D')  dp[st][en] = max(dp[st][en], func(st + 1, en, cnt + 1, str[st]));
		if (str[en] == 'D')  dp[st][en] = max(dp[st][en], func(st, en - 1, cnt + 1, str[en]));
	}
	else {
		if (str[st] == 'B')  dp[st][en] = max(dp[st][en], func(st + 1, en, cnt + 1, str[st]));
		if (str[en] == 'B')  dp[st][en] = max(dp[st][en], func(st, en - 1, cnt + 1, str[en]));
	}
	return dp[st][en];
}

int main() {
	scanf("%d", &n);
	cin >> str;
	int N = (3 * n) - 1;
	func(0, N, 0, ' ');
	printf("%d", dp[0][N]);
}

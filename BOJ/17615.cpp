#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

int tc, n, ans;
string str;

int func(int st, int d, char c) {
	int cnt = 0; bool flag = 0;
	for (int i = st; 0 <= i && i < n; i += d)
	{
		if (str[i] != c) {
			flag = 1; continue;
		}
		else if (flag) cnt++;
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> str;
	ans = func(0, 1, 'R');
	ans = min(ans, func(0, 1, 'B'));
	ans = min(ans, func(n - 1, -1, 'R'));
	ans = min(ans, func(n - 1, -1, 'B'));
	cout << ans;
}

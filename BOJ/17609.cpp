#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

int tc, len, ans;
string str;

void func(int st, int en, bool flag) {
	if (st >= en) {
		if (flag) ans = min(ans, 1);
		else ans = 0;
		return;
	}

	if (str[st] == str[en]) func(st + 1, en - 1, flag);
	else {
		if (flag) return;
		else {
			func(st + 1, en, 1);
			func(st, en - 1, 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> tc;
	while (tc--) {
		cin >> str;
		ans = 2;
		len = str.length();

		func(0, len - 1, 0);
		cout << ans << "\n";
	}
}

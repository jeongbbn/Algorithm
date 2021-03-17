#include<bits/stdc++.h>
using namespace std;

int st, en, a, b;
int main() {
	cin >> st >> en >> a >> b;
	int ans = abs(st - en);
	ans = min(ans, abs(st - a) + abs(en - b));
	ans = min(ans, abs(st - b) + abs(en - a));
	cout << ans;
}

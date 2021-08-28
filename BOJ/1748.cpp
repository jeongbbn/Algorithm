#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

string str;
ll len, n, tmp = 1, ans, digit=9;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;
	len = str.size();
	
	n = stol(str);
	for (int i = 0; i < len - 1; i++) tmp *= 10;
	ans = (n - tmp + 1) * len;
	
	for (int i = 1; i < len; i++) {
		ans += digit * i;
		digit *= 10;
	}

	cout << ans;
}

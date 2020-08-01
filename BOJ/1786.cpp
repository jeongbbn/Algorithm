#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

string str, p;
ll a[1000005] = { 1, };
ll hp, h;
vector<int>ans;

int main() {
	for (int i = 1; i < 1000001; i++)
		a[i] = a[i - 1] * 302 % mod;

	getline(cin, str);
	getline(cin, p);

	int n = str.length();
	int m = p.length();

	if (n < m) {
		printf("0");
		return 0;
	}

	//패턴 해시값
	for (int i = 0; i < m; i++)
		hp = (hp + p[i] * a[m - i - 1]) % mod;


	//문자열 해시값
	for (int i = 0; i < m; i++)
		h = (h + str[i] * a[m - i - 1]) % mod;

	if (hp == h) ans.push_back(1);
	for (int i = 1; i <= n - m; i++)
	{
		h = (h - a[m - 1] * str[i - 1]) % mod;
		if (h < 0) h += mod;
		h = h * 302 % mod;
		h = (h + str[i - 1 + m]) % mod;
		if (h == hp) ans.push_back(i + 1);
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}
}

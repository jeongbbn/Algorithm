#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pi;
#define mod 1000000007

int n, gcd1, gcd2;
vector<int>v;

int GCD(int a, int b) {
	if (b == 0) return a;
	return GCD(b, a % b);
}

pi func() {
	bool flag1 = 1, flag2 = 1;

	int idx = -1;
	for (int i = 0; i < n; i++)
	{
		if (v[i] % v[0] != 0) {
			if (idx != -1) flag1 = 0;
			else idx = i;
		}
	}
	if (idx == -1) return { -1, -1 };

	for (int i = 1; i < n; i++)
	{
		if (v[i] % v[idx] != 0) flag2 = 0;
	}

	if (!(flag1 | flag2)) return { -1, -1 };
	if (flag1 & flag2) return { g*v[idx], g*v[0] };
	if (flag1) return { g*v[0], g*v[idx] };
	if (flag2) return { g*v[idx], g*v[0] };
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	gcd1 = v[0];
	for (int i = 1; i < n; i++) {
		gcd1 = GCD(gcd1, v[i]);
	}

	gcd2 = v[2];
	for (int i = 3; i < n; i++) {
		gcd2 = GCD(gcd2, v[i]);
	}
	for (int i = 0; i < n; i++) v[i] /= g;

	pi ans = func();
	if (ans.first == -1) cout << -1;
	else cout << ans.first << " " << ans.second;
}

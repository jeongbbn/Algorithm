/*
Educational Codeforces Round 102 (Rated for Div. 2)
A. Replacing Elements
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
int tc, n, m;
int main() {
	cin >> tc;
	while (tc--) {
		vector<int>v;
		cin >> n >> m;
 
		bool ans = 1;
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			v.push_back(a);
			if (a > m) ans = 0;
		}
 
		sort(v.begin(), v.end());
 
		if (!ans) {
			if (v[0] + v[1] <= m) ans = 1;
			else ans = 0;
		}
 
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}

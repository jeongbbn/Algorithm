/*
Codeforces Round #695 (Div. 2)
A. Wizard of Orz

*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
int tc, ans, n;
vector<int>v;
 
int main() {
	cin >> tc;
	while (tc--) {
		cin >> n;
 
		if (n == 1) cout << "9";
		else {
			cout << "98";
			ans = 9;
			for (int i = 3; i <= n; i++)
			{
				cout << ans++;
				if (ans > 9) ans = 0;
			}
		}
		cout << "\n";
	}
}

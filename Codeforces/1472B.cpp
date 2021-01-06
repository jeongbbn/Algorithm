/*
Codeforces Round #693 (Div. 3)
B. Fair Division

*/

#include<iostream>
using namespace std;
int tc;
 
int main() {
	cin >> tc;
	while (tc--) {
		int n;
		int arr[3] = { 0, };
		bool ans = 1;
		cin >> n;
 
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			arr[a]++;
		}
 
		if (arr[2] % 2 == 0) {
			if (arr[1] % 2 == 1) ans = 0;
		}
		else {
			if (arr[1] % 2 == 1) ans = 0;
			else {
				if (arr[1] == 0) ans = 0;
			}
		}
 
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}

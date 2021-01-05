/*
 
Codeforces Round #693 (Div. 3)
A. Cards for Friends

*/

#include<iostream>
using namespace std;
 
int tc;
int func(int x) {
	while (x % 2 == 0) x /= 2;
	return x;
}
 
int main() {
	cin >> tc;
	while (tc--) {
		int w, h, n;
		cin >> w >> h >> n;
 
		int a = func(w);
		int b = func(h);
 
		if ((w / a)*(h / b) >= n) cout << "YES\n";
		else cout << "NO\n";
	}
}

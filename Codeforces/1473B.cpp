/*
Educational Codeforces Round 102 (Rated for Div. 2)
B. String LCM
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
 
int tc, n, m;
 
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
 
int main() {
	cin >> tc;
	while (tc--) {
		string a, b;
		cin >> a >> b;
 
		int alen = a.size();
		int blen = b.size();
 
		int m = alen*blen / gcd(alen, blen);
 
		string new_a = a;
		string new_b = b;
		for (int i = alen; i < m; i += alen) new_a += a;
		for (int i = blen; i < m; i+=blen) new_b += b;
 
		if (new_a == new_b) {
			cout << new_a << "\n";
		}
		else {
			cout << "-1\n";
		}
	}
}

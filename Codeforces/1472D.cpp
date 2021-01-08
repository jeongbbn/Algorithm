/*
Codeforces Round #693 (Div. 3)
D. Even-Odd Game

*/


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
int tc, n;
int main() {
	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<long long> v;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			v.push_back(a);
		}
 
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
 
		long long arr[2] = { 0, };
		for (int i = 0; i < v.size(); i++)
		{
			if (i % 2 == 0 && v[i] % 2 == 0) arr[0] += v[i];
			if (i % 2 == 1 && v[i] % 2 == 1) arr[1] += v[i];
		}
 
		if (arr[0] > arr[1]) cout << "Alice\n";
		else if (arr[0] == arr[1]) cout << "Tie\n";
		else cout << "Bob\n";
	}
}

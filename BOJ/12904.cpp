#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000000
typedef pair<string, bool>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

string s, t;
int ans, en;

bool find(string str) {
	int n = str.length();

	if (n == s.length()) {
		if (str == s) return 1;
		else return 0;
	}
	
	if (str[n - 1] == 'A') {
		str.pop_back();
		return find(str);
	}
	else {
		str.pop_back();
		reverse(str.begin(), str.end());
		return find(str);
	}
}


int main() {
	cin >> s >> t;
	printf("%d",find(t));
}

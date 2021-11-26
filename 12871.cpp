#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000000
#define mod 1000000
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

string s, t;
/*
반례
ababab
abab
1

ababa
ab
0

*/
int main() {
	cin >> s >> t;
	if (s.length() > t.length())
		swap(s, t);

	bool ans = 1;
	int j = 0, i = 0;
	int slen = s.length();
	int tlen = t.length();
	int len = slen * tlen;

	while (len--) {
		if (s[j] != t[i]) {
			ans = 0; break;
		}
		j++;
		i++;
		if (j >= slen) j = 0;
		if (i >= tlen) i = 0;
	}
	
	printf("%d", ans);
}

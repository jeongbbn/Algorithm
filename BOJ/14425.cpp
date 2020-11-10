#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

map<string, bool>mapp;
int n, m, ans;
string str;
int main() {
	scanf("%d %d", &n, &m);
	while (n--) {
		string tmp;
		cin >> tmp;
		mapp.insert({ tmp,1 });
	}
	
	while (m--) {
		string s;
		cin >> s;
		if (mapp.find(s) != mapp.end()) ans++;
	}
	cout << ans;
}

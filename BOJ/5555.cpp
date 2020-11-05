#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

string p;
int n, ans;
int main() {
	cin >> p;
	scanf("%d", &n);
	while (n--) {
		string a;
		cin >> a;

		for (int i = 0; i < 10; i++) {
			string tmp = a.substr(i) + a.substr(0, i);
			if (tmp.find(p) != string::npos) {
				ans++; break;
			}
		}
	}
	printf("%d", ans);
}

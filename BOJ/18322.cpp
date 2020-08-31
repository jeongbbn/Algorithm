#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

int n, m;
string str[105];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> str[i];

	int sum = 0;
	for (int i = 0; i < n; i++) {
		int len = str[i].length();
		if (sum + len <= m) {
			cout << str[i] << " "; sum += len;
		}
		else { 
			cout << "\n" << str[i] << " "; sum = len; 
		}
	}
}

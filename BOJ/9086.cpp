#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int T;
string str;
int main() {
	scanf("%d ", &T);
	while (T--) {
		cin >> str;
		int len = str.length();
		printf("%c%c\n", str[0], str[len - 1]);
	}
}

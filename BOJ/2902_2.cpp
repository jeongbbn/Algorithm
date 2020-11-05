/*
백준 2902
KMP는 왜 KMP일까?
find 연습
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int pos = 0;
vector<string>v;
int main() {
	string str;
	cin >> str;
	printf("%c", str[0]);
	while ((pos = str.find('-', pos + 1)) != string::npos) {
		printf("%c", str[pos + 1]);
	}
}

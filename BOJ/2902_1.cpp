/*
백준 2902
KMP는 왜 KMP일까?
strtok 연습
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

vector<string>v;
int main() {
	string str;
	cin >> str;
	char *res;
	res = strtok((char *)str.c_str(), "-");
	while (res != NULL) {
		string tmp = "";
		tmp += res;
		res = strtok(NULL, "-");
		v.push_back(tmp);
	}
	for (int i = 0; i < v.size(); i++)
	{
		printf("%c", v[i][0]);
	}
}

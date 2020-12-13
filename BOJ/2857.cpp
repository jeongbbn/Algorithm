#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

vector<int>ans;
int main() {
	for (int i = 0; i < 5; i++)
	{
		string str;
		cin >> str;
		if (str.find("FBI") != string::npos) ans.push_back(i + 1);
	}
	if (ans.size() == 0) printf("HE GOT AWAY!");
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}
}

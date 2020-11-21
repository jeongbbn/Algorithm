#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int n;
string ans;
vector<string>v;

int main() {
	scanf("%d", &n);
	while (n--) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	for (int i = 0; i < v[0].size(); i++)
	{
		for (int j = 1; j < v.size(); j++)
		{
			if (v[0][i] != v[j][i]) {
				ans += '?';
				break;
			}
		}
		if (ans.size() != i + 1) ans += v[0][i];
	}
	cout << ans;
	return 0;
}

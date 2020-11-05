#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

string str;
vector<int>ans;
int main() {
	cin >> str;
	reverse(str.begin(), str.end());
	int len = str.size(); len--;

	int cut = 0;
	while (cut <= len) {
		string tmp = str.substr(cut, 3);
		int digit = 1; int sum = 0;
		for (int i = 0; i < tmp.size(); i++)
		{
			sum += ((tmp[i]-'0') * digit);
			digit *= 2;
		}
		ans.push_back(sum);
		cut += 3;
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d", ans[i]);
	}
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pi;

int n, len;
vector<string>v;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str; cin >> str;
		v.push_back(str);
		if(len == 0) len = str.size();
	}

	map<string, int>m;
	for (int k = len - 1; k >= 0; k--)
	{
		bool flag = 0;
		for (int i = 0; i < n; i++)
		{
			string str = v[i].substr(k);
			if (m.find(str) != m.end()) {
				flag = 1;
				break;
			}
			m[str]++;
		}
		if (!flag) {
			cout << len - k;
			return 0;
		}
	}
}

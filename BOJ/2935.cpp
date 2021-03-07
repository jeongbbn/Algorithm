#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

string str1, str2, a, ans;
int main() {
	cin >> str1 >> a >> str2;
	if (a == "+") {
		reverse(str1.begin(), str1.end());
		reverse(str2.begin(), str2.end());

		int len = min(str1.size(), str2.size());
		for (int i = 0; i < len; i++)
		{
			if (str1[i] == '1' && str2[i] == '1') ans += "2";
			else if (str1[i] == '1' && str2[i] == '0') ans += "1";
			else if (str1[i] == '0' && str2[i] == '1') ans += "1";
			else ans += "0";
		}

		if (len < str1.size()) ans += str1.substr(len);
		else if (len < str2.size()) ans += str2.substr(len);

		reverse(ans.begin(), ans.end());
		cout << ans;
	}
	else {
		int a = (int)str1.size() - 1;
		int b = (int)str2.size() - 1;

		printf("1");
		for (int i = 0; i < a + b; i++) printf("0");
	}
}

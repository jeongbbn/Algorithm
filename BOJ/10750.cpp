#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string str, pattern, ans;
int k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str >> pattern;

	for (int i = 0; i < str.size(); i++)
	{
		ans += str[i];

		int ans_len = ans.size();
		int pattern_len = pattern.size();
		if (ans_len >= pattern_len) {
			if (ans.substr(ans_len - pattern_len) == pattern) {
				ans = ans.erase(ans_len - pattern_len);
			}
		}
	}
	cout << ans;
}

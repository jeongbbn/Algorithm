#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

int n;
string str1, str2;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n--) {
		cin >> str1 >> str2;

		int one = 0, zero = 0;
		for (int i = 0; i < str1.size(); i++)
		{
			if (str1[i] == str2[i]) continue;
			if (str1[i] == '1') one++;
			else zero++;
		}
		cout << max(one, zero) << "\n";
	}
}

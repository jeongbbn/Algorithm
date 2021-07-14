#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, T;
string str;

int main() {
	scanf("%d ", &T);

	while (T--) {
		getline(cin, str);
		int len = str.length();

		int chk[26] = { 0, };
		for (int i = 0; i < len; i++)
		{
			int x = str[i] - 97;
			if (x >= 0 && x < 26) chk[x]++;
		}

		int maxx = *max_element(chk, chk + 26);
		char ans = '*';
		for (int i = 0; i < 26; i++)
		{
			if (ans != '*' && chk[i] == maxx) ans = '?';
			else if (ans == '*' && chk[i] == maxx) ans = i + 97;
		}

		printf("%c\n", ans);
	}
}

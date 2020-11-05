#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int n;
bool cnt[30];
int main() {
	scanf("%d", &n);
	while (n--) {
		string s;
		cin >> s;
		fill(cnt, cnt + 26, 0);

		for (int i = 0; i < s.size(); i++)
		{
			cnt[s[i] - 65] = 1;
		}

		int ans = 0;
		for (int i = 0; i < 26; i++)
		{
			if (!cnt[i]) ans += 65 + i;
		}
		printf("%d\n", ans);
	}
}

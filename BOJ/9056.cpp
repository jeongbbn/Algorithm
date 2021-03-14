#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000000
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		string p, s;
		cin >> p >> s;

		int chk[30] = { 0, };
		
		int plen = p.length();
		int slen = s.length();

		for (int i = 0; i < plen; i++)
		{
			chk[p[i] - 65] = 1;
		}

		bool ans = 1;
		for (int i = 0; i < slen; i++) {
			if (!chk[s[i] - 65]) ans = 0;
			chk[s[i] - 65] = 2;
		}

		int cnt = 0;
		for (int i = 0; i < 30; i++)
			if (chk[i] == 2) cnt++;
		if (cnt != plen) ans = 0;

		if (ans) printf("YES\n");
		else printf("NO\n");
	}

}

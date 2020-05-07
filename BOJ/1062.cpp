#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;
vector<char>ABC;

int n, k, ans;
int key[30], visit[30];
char str[55][20];

void C(int idx, int t) {
	if (t == k) {
		int cnt = n;
		for (int i = 0; i < n; i++)
		{
			bool flag = 1;
			for (int j = 0; str[i][j] != '\0'; j++)
			{
				if (str[i][j] == 'a' || str[i][j] == 'n') continue;
				if (str[i][j] == 'c' || str[i][j] == 't') continue;
				if (str[i][j] == 'i') continue;
				for (int m = 0; m < k; m++)
				{
					if (str[i][j] == ABC[key[m]]) { flag = 0; break; }
					else flag = 1;
				}
				if (flag) { cnt--; break; }
			}
		}

		ans = max(cnt, ans);
		return;
	}

	for (int i = idx; i < ABC.size(); i++)
	{
		if (visit[i]) continue;
		visit[i] = 1;
		key[t] = i;
		C(i, t + 1);
		visit[i] = 0;
	}

}

bool check[27];
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str[i]);
	}

	if (k < 5) { printf("0"); return 0; }
	k -= 5;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; str[i][j] != '\0'; j++)
		{
			if (str[i][j] == 'a' || str[i][j] == 'n') continue;
			if (str[i][j] == 'c' || str[i][j] == 't') continue;
			if (str[i][j] == 'i' ) continue;

			if (check[str[i][j] - 97]) continue;
			check[str[i][j] - 97] = 1;
			ABC.push_back(str[i][j]);
		}
	}

	if (k > ABC.size()) k = ABC.size();
	C(0, 0);
	printf("%d",ans);
}
	

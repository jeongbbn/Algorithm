#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n,k;
bool dp[35][35][35][500];

bool dfs(int a, int b, int c, int cnt, string str) {

	if (a + b + c == n) { 
		if (cnt == k) {
			cout << str;
			exit(0);
		}
		return 0;
	}

	if (dp[a][b][c][cnt]) return 0;
	dp[a][b][c][cnt] = 1;


	if (dfs(a + 1, b, c, cnt, str + "A")) return 1;
	if (dfs(a, b + 1, c, cnt + a, str + "B")) return 1;
	if (dfs(a, b, c + 1, cnt + a + b, str + "C")) return 1;

	return 0;
}

int main() {
	scanf("%d%d", &n, &k);
	dfs(0, 0, 0, 0, "");
	printf("-1");
} 

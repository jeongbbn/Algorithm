#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 1e9+10

int n, m, k;
int d[105][105], nxt[105][105];
queue<int>q;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (d[a][b] < c) continue;
		d[a][b] = c;
		nxt[a][b] = b;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (d[i][j] > d[i][k] + d[k][j]) {
					nxt[i][j] = nxt[i][k];
					d[i][j] = d[i][k] + d[k][j];
				}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j]==INF)  printf("0 ");
			else printf("%d ", d[i][j]);
		}
		printf("\n");
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == 0 || d[i][j] == INF) printf("0\n");
			else {
				vector<int>ans;
				int cur = i;
				while (cur!=j) {
					ans.push_back(cur);
					cur = nxt[cur][j];
					}
				ans.push_back(j);
				printf("%d ", ans.size());
				for (int i = 0; i < ans.size(); i++)
					printf("%d ", ans[i]);
				printf("\n");
			}

		}
	}






}

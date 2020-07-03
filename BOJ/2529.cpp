#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;

int n, key[10], minn[10], maxx[10], chk;
bool visit[10];
string str;

void dfs(int k) {
	if (k == n + 1) {
		if (chk == 0) {
			for (int i = 0; i < n + 1; i++)
				minn[i] = key[i];
		}
		for (int i = 0; i < n + 1; i++)
			maxx[i] = key[i];
		chk++;
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (visit[i]) continue;
		if (k != 0) {
			if (str[k * 2 - 2] == '<' && key[k-1] < i) key[k] = i; 
			else if(str[k * 2 - 2] == '>' && key[k - 1] > i) key[k] = i;
			else continue;
		}
		else key[k] = i;
		visit[i] = 1;
		dfs(k + 1);
		visit[i] = 0;
	}
}
int main() {
	scanf("%d ", &n);
	getline(cin,str);
	dfs(0);
	for (int i = 0; i < n+1; i++)
		printf("%d", maxx[i]);
	printf("\n");
	for (int i = 0; i < n + 1; i++)
		printf("%d", minn[i]);
}

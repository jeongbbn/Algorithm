#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

bool ans[105], visit[105];
int arr[105];
int chk;
bool flag;

void dfs(int x) {
	if (visit[arr[x]]) { 
		chk = arr[x]; 
		flag = 1;
	}

	else { 
		visit[arr[x]] = 1; 
		dfs(arr[x]); 
	}

	if (flag) ans[x] = 1;
	if (chk == x) flag = 0;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		fill(visit, visit + n + 1, 0);
		visit[i] = 1;
		dfs(i);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == 1) cnt++;
	}

	printf("%d\n", cnt);

	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == 1) printf("%d\n", i);
	}
}

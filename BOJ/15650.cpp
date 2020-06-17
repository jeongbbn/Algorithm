#include <iostream>
using namespace std;

int n, m, arr[8];
bool visit[9];

void dfs(int p) {
	if (p == m) {
		for (int i = 0; i < m; i++)
			printf("%d ",arr[i]);
		printf("\n");
		return;
	}

	int flag;
	if (p == 0) flag = 1;
	else flag = arr[p - 1];

	for (int i = flag; i <= n; i++){
		if (!visit[i]){
			visit[i] = 1;
			arr[p] = i;
			dfs(p + 1);
			visit[i] = 0;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	dfs(0);

}

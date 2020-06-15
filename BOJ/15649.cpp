#include <iostream>
using namespace std;

int m, n, arr[8];
bool visited[9];

void dfs(int p) {
	if (p == m) {
		for (int i = 0; i < m; i++)
			printf("%d ",arr[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i < n+1; i++){
		if (!visited[i]) {
			visited[i] = 1;
			arr[p] = i;

			dfs(p+1); //전역변수로 p를 잡고 p++을 쓰면, 매번 올라가서 index를 벗어난다.
			visited[i] = 0;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	dfs(0); //p를 1로 잡고 시작하면 안된다. case가 3 1인 경우 dfs(1)하면 바로 끝남.
}//참고로, p : 리스트에 들어있는 개수다. 애초에 1이면 말이 안되네 그러게//

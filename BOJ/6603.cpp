#include <iostream>
#include <algorithm>
using namespace std;

int k, ans[14], arr[14];
bool visit[14];

//void dfs(int cnt, int idx) {
//	if (cnt == 6) {
//		for (int i = 0; i < 6; i++)
//			printf("%d ", ans[i]);
//		printf("\n");
//		return;
//	}
//
//	for (int i = idx; i < k; i++)
//	{
//		if (visit[i]) continue;
//		visit[i] = 1;
//		ans[cnt] = arr[i];
//		dfs(cnt + 1, i);
//		visit[i] = 0;
//	}
//}


void nextpermu(){
	int * select = (int *)malloc(sizeof(int) * k);
	for (int i = 0; i < k; i++)
	{
		if (i < 6) select[i] = 0;
		else select[i] = 1;
	}
	do {
		for (int i = 0; i < k; i++){
			if (select[i] == 0) printf("%d ", arr[i]);
		}
		printf("\n");
	} while (next_permutation(select, select + k));
}

int main() {
	while (1) {
		scanf("%d", &k);
		if (k == 0) return 0;
		for (int i = 0; i < k; i++)
			scanf("%d", &arr[i]);
		//dfs(0,0);
		nextpermu();
		printf("\n");
	}
}

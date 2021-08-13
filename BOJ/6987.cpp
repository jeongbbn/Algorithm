#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int dx[] = { 0,0,0,0,0,1,1,1,1,2,2,2,3,3,4 };
int dy[] = { 1,2,3,4,5,2,3,4,5,3,4,5,4,5,5 };
bool anss[4];
int idx;
void dfs(int k, int arr[6][3], int score[6][3], int idx) {
	if (k == 15) {
		bool ans = 1;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[i][j] != score[i][j]) {
					ans = 0; return;
				}
			}
		}
		
		anss[idx] = 1;
		return;
	}

	arr[dx[k]][0]++; arr[dy[k]][2]++;
	dfs(k + 1, arr, score, idx);
	arr[dx[k]][0]--; arr[dy[k]][2]--;

	arr[dx[k]][1]++; arr[dy[k]][1]++;
	dfs(k + 1,arr,score, idx);
	arr[dx[k]][1]--; arr[dy[k]][1]--;

	arr[dx[k]][2]++; arr[dy[k]][0]++;
	dfs(k + 1, arr, score, idx);
	arr[dx[k]][2]--; arr[dy[k]][0]--;
}

int main() {

	for (int t = 0; t < 4; t++)
	{
		int score[6][3] = { 0, };

		for (int j = 0; j < 6; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				scanf("%d", &score[j][k]);
			}
		}

		int arr[6][3] = { 0, };
		dfs(0, arr, score, t);
	}

	for (int i = 0; i < 4; i++)
	{
		printf("%d ", anss[i]);
	}
}

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int sudoku[10][10];
vector<pi>arr;
int key[100];

bool row[9][10];
bool column[9][10];
bool box[3][3][10];
bool flag;
void print() {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", sudoku[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}
void dfs(int k) {
	if (!flag && k == arr.size()) {

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				printf("%d ", sudoku[i][j]);
			}
			printf("\n");
		}
		flag = 1;
		exit(0);
		return;
	}

	int x = arr[k].first;
	int y = arr[k].second;

	for (int i = 1; i < 10; i++)
	{
		if (row[x][i]) continue;
		if (column[y][i]) continue;
		if (box[x / 3][y / 3][i]) continue;

		key[k] = i;
		row[x][i] = 1;
		column[y][i] = 1;
		box[x / 3][y / 3][i] = 1;
		sudoku[x][y] = i;

		dfs(k + 1);

		row[x][i] = 0;
		column[y][i] = 0;
		box[x / 3][y / 3][i] = 0;


	}
}

int main() {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &sudoku[i][j]);
			if (sudoku[i][j] == 0) arr.push_back({ i,j });
			row[i][sudoku[i][j]] = 1;
			column[j][sudoku[i][j]] = 1;

			box[i / 3][j / 3][sudoku[i][j]] = 1;
		}
	}

	dfs(0);

}

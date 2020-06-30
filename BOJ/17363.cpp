#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;


char arr[105][105], ans[105][105];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &arr[i][j]);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '-') ans[j][i] = '|';
			else if (arr[i][j] == '|') ans[j][i] = '-';
			else if (arr[i][j] == '/') ans[j][i] = '\\';
			else if (arr[i][j] == '\\') ans[j][i] = '/';
			else if (arr[i][j] == '^') ans[j][i] = '<';
			else if (arr[i][j] == '<') ans[j][i] = 'v';
			else if (arr[i][j] == 'v') ans[j][i] = '>';
			else if (arr[i][j] == '>') ans[j][i] = '^';
			else {
				ans[j][i] = arr[i][j];
			}

		}	
	}



	for (int i = m-1; i >= 0; i--) {
		for (int j = 0; j < n; j++)
			printf("%c", ans[i][j]);
		printf("\n");
	}
}

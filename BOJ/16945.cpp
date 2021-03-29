#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int arr[5][5];
int tmp[5][5];

bool check() {
	int sum1 = 0, sum2 = 0, sum3 = 0;
	for (int i = 0; i < 3; i++) {
		sum1 += arr[0][i];
		sum2 += arr[1][i];
		sum3 += arr[2][i];
	}
	if (sum1 != sum2 || sum2 != sum3 || sum1!= sum3) return 0;

	sum1 = 0; sum2 = 0; sum3 = 0;
	for (int i = 0; i < 3; i++) {
		sum1 += arr[i][0];
		sum2 += arr[i][1];
		sum3 += arr[i][2];
	}
	if (sum1 != sum2 || sum2 != sum3 || sum1!= sum3) return 0;

	sum1 = arr[0][0] + arr[1][1] + arr[2][2];
	sum2 = arr[0][2] + arr[1][1] + arr[2][0];

	if (sum1 != sum2) return 0;
	return 1;
}


int main() {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dfs(0);
	printf("%d", maxx);
}

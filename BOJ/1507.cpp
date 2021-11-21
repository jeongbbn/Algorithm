#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<map>
#include <string>
using namespace std;
#define INF 800*1000
typedef pair<int, int>pii;

bool d[25][25];
int main() {
	int n,arr[25][25];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (i==j || j == k || i == k) continue;
				// 1->3 == 1->1 && 1->3 방지
				// 1->1 == 1->2 && 2->1 방지

				if (arr[i][j] == arr[i][k] + arr[k][j]) {
					d[i][k] = 1;
					d[k][j] = 1;
				}
				else if (arr[i][j] > arr[i][k] + arr[k][j]) {
					printf("-1");
					return 0;
				}
			}

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (d[i][j]) {
				ans += arr[i][j];
			}
		}
	printf("%d", ans/2); //ㄴ ㄱ 둘 다 계산했으므로
}

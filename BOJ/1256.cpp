#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
using namespace std;
#define INF 1e9+10

int n, m, k;
long long c[201][201];
int main() {
	scanf("%d%d%d", &n, &m, &k);

	c[0][0]=c[1][0] = c[1][1] = 1;
	for (int i = 2; i <= 200; i++) {
		for (int j = 0; j <= i; j++) {
			c[i][j] = min((long long)1e9 + 7, c[i - 1][j] + c[i - 1][j - 1]);
		}//중복조합이므로 최대 n+m-1 따라서 200
	}

	if (c[n + m][n] < k) { printf("-1"); return 0; }
	//모든 조합수보다 k가 클 경우 : 말이 안되는 경우

	int a = n, b = m;
	n--; //n+m-1, 왜냐하면 a _ _ _ , z _ _ _에서 z _ _ _는 +3부터 시작
	for (int i = 0; i < a+b; i++)
	{
		if (c[n+m][m] < k) {
			k -= c[n + m][m];
			printf("z");
			m--;
		}
		else {
			printf("a");
			n--;
		}
	}

}

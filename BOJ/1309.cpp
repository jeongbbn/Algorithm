#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include <string>
#include<map>
#include<stack>
using namespace std;
#define INF 1e9+10
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
typedef pair<int, int>p;
//bool outrange(int x, int y) {
//	if (x < 0 || y < 0 || x >= n || y >= m) return 1;
//	return 0;
//}
int n,d[100005][3];
int main() {
	scanf("%d", &n);
	
	d[1][0] = d[1][1] = d[1][2] = 1;
	for (int i = 2; i <= n; i++)
	{
		d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2])%9901;
		d[i][1] = (d[i - 1][0] + d[i - 1][2])%9901;
		d[i][2] = (d[i - 1][0] + d[i - 1][1])%9901;
	}

	printf("%d", (d[n][0] + d[n][1] + d[n][2])%9901);

}

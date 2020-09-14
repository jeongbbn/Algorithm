#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> pii;

int n;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool check[35][35];
double p[4];

double ans;
void P(int k, int x, int y, double pro) {
	if (k == n) {
		ans += pro;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (check[nx][ny]) continue;
		check[nx][ny] = 1;
		P(k + 1, nx, ny, pro * p[i]);
		check[nx][ny] = 0;
	}

}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < 4; i++)
	{
		int a;
		scanf("%d", &a);
		p[i] = a * 0.01;
	}
	check[15][15] = 1;
	P(0, 15, 15, 1.00);
	printf("%.9f", ans);
}

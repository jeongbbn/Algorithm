#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;


bool check[105][105];
int main() {

	for (int i = 0; i < 4; i++)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);

		for (int i = b; i < d; i++)
		{
			for (int j = a; j < c; j++)
			{
				check[i][j] = 1;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (check[i][j] == 1) cnt++;
		}
	}

	printf("%d", cnt);

}

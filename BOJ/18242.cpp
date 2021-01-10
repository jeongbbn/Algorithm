#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int n, m;
char arr[105][105];

int main() {

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &arr[i][j]);
		}
	}

	int p = INF;
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == '#') cnt++;
		}
		if (cnt == 1) {
			p = i;
			break;
		}
	}

	if (p != INF) {
		int now, chk;
		for (int i = 0; i < m; i++)
		{
			if (arr[p][i] == '.') {
				if (arr[p - 1][i] == '#') now = i;
			}
			else chk = i;
		}

		if (now < chk) printf("LEFT");
		else printf("RIGHT");
	}

	else {
		for (int i = 0; i < m; i++)
		{
			int cnt = 0;
			for (int j = 0; j <n; j++)
			{
				if (arr[j][i] == '#') cnt++;
			}
			if (cnt == 1) {
				p = i;
				break;
			}
		}

		int now, chk;
		for (int i = 0; i < n; i++)
		{
			if (arr[i][p] == '.') {
				if (arr[i][p - 1] == '#') now = i;
			}
			else chk = i;
		}

		if (now < chk) printf("UP");
		else printf("DOWN");
	}

}

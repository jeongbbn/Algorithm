#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int arr[15][6];
int r[8][6] = { {0,0,0,0,0,0},{0,0,1,1,1,1},
{0,1,0,0,1,1}, {0,1,1,1,0,0}, 
{1,0,0,1,1,0}, {1,0,1,0,0,1},
{1,1,0,1,0,1},{1,1,1,0,1,0} };

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	vector<int>ans;
	for (int i = 0; i < n; i++)
	{
		bool flag = 0;
		for (int j = 0; j < 8; j++)
		{
			int cnt = 0;
			for (int k = 0; k < 6; k++)
			{
				if (arr[i][k] != r[j][k]) cnt++;
			}
			if (cnt <= 1) {
				ans.push_back(j); 
				flag = 1;
				break;
			}		
		}
		if (!flag) { printf("%d",i + 1); return 0; }
	}
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%c", ans[i] + 65);
	}
}

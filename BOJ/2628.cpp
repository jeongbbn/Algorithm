#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

vector<int>column, row;
int n, m ,t;
int main() {
	scanf("%d%d", &m, &n);
	scanf("%d", &t);

	column.push_back(0);
	row.push_back(0);

	for (int i = 0; i < t; i++)
	{	
		int a, b;
		scanf("%d %d", &a, &b);
		
		if (a == 0) column.push_back(b);
		else row.push_back(b);
	}

	column.push_back(n);
	row.push_back(m);

	sort(column.begin(), column.end());
	sort(row.begin(), row.end());

	int csize = column.size();
	int rsize = row.size();

	int maxx = -1;
	for (int i = 0; i < csize - 1; i++)
	{
		int r = column[i + 1] - column[i];
		for (int j = 0; j < rsize - 1; j++)
		{
			int c = row[j + 1] - row[j];

			int s = c * r;
			maxx = max(maxx, s);
		}
	}
	printf("%d", maxx);

}

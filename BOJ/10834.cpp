#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int main() {
	int n;
	scanf("%d", &n);

	bool di = 0;
	int before = 1;

	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		if (c == 1) { 
			if(di)  di = 0;
			else di = 1;}
		before = b * (before / a);
	}
	printf("%d %d",di, before);
	return 0;
}

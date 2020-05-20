#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;


int eden_hazard;


int main() {
	scanf("%d", &eden_hazard);
	for (int i = 0; i < eden_hazard; i++)
	{
		int n;
		scanf("%d", &n);

		int maxx = 0;
		char ans[25];
		for (int j = 0; j < n; j++)
		{
			int money;
			char name[25];
			scanf("%d", &money);
			scanf("%s", name);

			if (money > maxx) {
				maxx = money;
				int k;
				for (k = 0; name[k] != '\0' ; k++)
					ans[k] = name[k];

				ans[k] = '\0';
			}
		}
		printf("%s\n", ans);
	}
}

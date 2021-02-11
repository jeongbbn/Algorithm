#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int j = 0; j < t; j++) {
		int m, n, x, y;
		scanf("%d%d%d%d", &m, &n,&x,&y);

		if (x == m) x = 0;
		if (y == n) y = 0;
		
		int i = x;
		bool flag = false;
		for (; i <= m*n; i+=m)
		{
			if (i%n == y) {
				if (i == 0) continue;
				printf("%d\n", i);
				flag = true;
				break;
			}
		}
		if (!flag) printf("-1\n");
	}

}

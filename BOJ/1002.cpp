#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n, x1,x2,y1,y2,r1,r2,d;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		d = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);

		if ((r1 + r2)*(r1 + r2) == d || ((r2 - r1)*(r2 - r1) == d) && d != 0) {
			printf("1\n");
		}

		else if ((r1 + r2)*(r1 + r2) < d || (r2 - r1)*(r2 - r1) > d || (r1 != r2 && d == 0)) {
			printf("0\n");
		}

		else if (r1 == r2 && d == 0) {
			printf("-1\n");
		}
		else {
			printf("2\n");
		}
	}
}

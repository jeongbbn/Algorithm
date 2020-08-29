#include <iostream>
using namespace std;

int cnt, n, r, c;

void z(int a, int b, int n) {

	int k = 1 << (n - 1);
	int x = (r / k) * k;
	int y = (c / k) * k;

	if (x == a && y == b + k) cnt += 1 * k * k;
	else if (x == a + k && y == b) cnt += 2 * k * k;
	else if (x == a + k && y == b + k) cnt += 3 * k * k;
	if (n == 1) { printf("%d", cnt); return; }
	z(x, y, n - 1);
}


int main() {
	scanf("%d%d%d", &n, &r, &c);
	z(0, 0, n);
}

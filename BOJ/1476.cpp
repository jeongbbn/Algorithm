#include <iostream>
using namespace std;

int main() {
	int e,s,m;
	scanf("%d%d%d", &e, &s, &m);

	if (e == 15) e = 0;
	if (s == 28) s = 0;
	if (m == 19) m = 0;

	for (int i = s; i <= 15*28*19; i+=28)
	{
		if (i % 15 == e && i % 19 == m) {
			if (i == 0) i = 15 * 28 * 19;
			printf("%d", i);
			return 0;
		}
	}

}

#include <iostream>
#include <algorithm>
using namespace std;

int n, button[3] = {300, 60, 10},cnt[3];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 3; i++)
	{
		if (n < button[i]) continue;
		cnt[i] = n / button[i];
		n = n % button[i];
	}
	if (n != 0) {
		printf("-1");
		return 0;
	}

	for (int i = 0; i < 3; i++)
		printf("%d ", cnt[i]);
}

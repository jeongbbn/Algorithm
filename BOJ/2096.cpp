#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int midp[3];
int mxdp[3];

int main() {
	int n;
	scanf("%d", &n);

	scanf("%d%d%d", &midp[0], &midp[1], &midp[2]);
	mxdp[0] = midp[0]; mxdp[1] = midp[1]; mxdp[2] = midp[2];

	for (int i = 0; i < n-1; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		int t1, t2, t3, t4, t5, t6;
		t1 = a + max(mxdp[0], mxdp[1]);
		t2 = a + min(midp[0], midp[1]);

		t3 = b + max(mxdp[0], max(mxdp[1], mxdp[2]));
		t4 = b + min(midp[0], min(midp[1], midp[2]));

		t5 = c + max(mxdp[1], mxdp[2]);
		t6 = c + min(midp[1], midp[2]);


		mxdp[0] = t1; mxdp[1] = t3; mxdp[2] = t5;
		midp[0] = t2; midp[1] = t4; midp[2] = t6;
	}

	int minn = midp[0];
	int maxx = mxdp[0];
	for (int i = 1; i < 3; i++)
	{
		maxx = max(maxx, mxdp[i]);
		minn = min(minn, midp[i]);
	}

	printf("%d %d", maxx, minn);


}

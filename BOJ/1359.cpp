#include<bits/stdc++.h>
using namespace std;

typedef struct vals {
	int up;
	int down;
}val;

int n, m, k;
double ans;

int C(int n, int r) {
	int up = 1, down = 1;
	for (int y = r; y >= 1; y--)
	{
		up *= n--;
		down *= y;
	}
	return up / down;
}

int main() {#include<bits/stdc++.h>
using namespace std;

typedef struct vals {
	int up;
	int down;
}val;

int n, m, k;
double ans;

int C(int n, int r) {
	int up = 1, down = 1;
	for (int y = r; y >= 1; y--)
	{
		up *= n--;
		down *= y;
	}
	return up / down;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	int parent = C(n, m);
	int child = 0;
	for (int i = k; i <= m; i++) {
		child += C(m,i) * C(n-m, m-i);
	}

	double ans = (double)child / parent;
	printf("%.9f", ans);
}
	scanf("%d%d%d", &n, &m, &k);
	int parent = C(n, m);
	int child = 0;
	for (int i = k; i <= m; i++) {
		child += C(m,i) * C(n-m, m-i);
	}

	double ans = (double)child / parent;
	printf("%.9f", ans);
}

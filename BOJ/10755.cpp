#include <bits/stdc++.h>
using namespace std;

vector<int>uf(100005, -1);

int find(int x) {
	if (uf[x] < 0) return x;
	return uf[x] = find(uf[x]);
}

void merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x < y) { uf[y] = x; } 
	else { uf[x] = y; }
}

int main() {
	int g, p;
	scanf("%d%d", &g, &p);
	int cnt = 0;
	for (int i = 0; i < p; i++)
	{
		int a;
		scanf("%d", &a);

		int x = find(a);
		if (x == 0) break;
		merge(x-1, x);
		cnt++; //더이상 도킹할 수 없다면 break문으로 탈출하므로
		//cnt가 곧 정답이 된다.
	}
	printf("%d", cnt);
}

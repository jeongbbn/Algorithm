
#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include <string>
#include<map>
#include <algorithm>
#include<stack>
using namespace std;
#define INF 1e9+10
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
typedef pair<int, int>p;
//bool outrange(int x, int y) {
//	if (x < 0 || y < 0 || x >= n || y >= m) return 1;
//	return 0;
//}

int n;
int parent[27];
int lc[27];
int rc[27];

void preorder(int cur) {
	printf("%c", cur+65);
	if (lc[cur] != 0) preorder(lc[cur]);
	if (rc[cur] != 0) preorder(rc[cur]);
}

void inorder(int cur) {
	if (lc[cur] != 0) inorder(lc[cur]);
	printf("%c", cur + 65);
	if (rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur) {
	if (lc[cur] != 0) postorder(lc[cur]);
	if (rc[cur] != 0) postorder(rc[cur]);
	printf("%c", cur + 65);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char a, b, c;
		scanf(" %c %c %c", &a, &b, &c);
		a = a - 65;

		if (b == '.') b = 0;
		else b = b - 65;

		if (c == '.') c = 0;
		else c = c - 65;

		lc[a] = b;
		rc[a] = c;
		parent[c] = a;
		parent[b] = a;

	}
	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
	printf("\n");
}

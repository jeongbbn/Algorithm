#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include <string>
#include<map>
using namespace std;
#define INF 1e9+10
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
typedef pair<int, int>p;
//bool outrange(int x, int y) {
//	if (x < 0 || y < 0 || x >= n || y >= m) return 1;
//	return 0;
//}

int t, n;
vector<int>parent(200005, -1);
int find(int a) {
	if (parent[a] < 0) return a;
	return parent[a] = find(parent[a]);
}

int merge(int a, int b) {

	int x = find(a);
	int y = find(b);

	if (x == y) {
		return -parent[x];
	}

	if (parent[x] <= parent[y]) {
		parent[x] += parent[y];
		parent[y] = x;
		return -parent[x];
	}
	else if (parent[x] > parent[y]) {
		parent[y] += parent[x];
		parent[x] = y;
		return -parent[y];
	}
}


int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		map<string, int>m;
		scanf("%d", &n);
		int size=0;
		for (int i = 0; i <= 2*n; i++)
			parent[i] = -1;

		for (int i = 0; i < n; i++)
		{
			char s1[25],s2[25];
			scanf("%s %s", s1, s2);

			if (m.find(s1) == m.end()) {
				m[s1] = size;
				size++;
			}
			if (m.find(s2) == m.end()) {
				m[s2] = size;
				size++;
			}
			printf("%d\n",merge(m[s1], m[s2]));
			
		}

	}
}

#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<map>
#include <string>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, m, k;
int arr[10][10];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
vector<pi>air;
queue<pi>q;
bool outrange(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>m - 1) return 1;
	return 0;
}

vector<int>parent(1005, -1);
int find(int a) {
	if (parent[a] < 0) return a;
	return parent[a] = find(parent[a]);
}

bool merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y) return 0;

	if (parent[x] == parent[y])parent[x]--;
	if (parent[x] < parent[y]) parent[y] = x;
	else parent[x] = y;
	return 1;
}

vector<pii>up;
vector<pii>down;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m+1; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		up.push_back({ c,{a,b } });
		down.push_back({ -c,{a,b} });
	}
	sort(up.begin(), up.end());
	sort(down.begin(), down.end());

	int cnt1=0, until1=0;
	for (int i = 0; i < up.size(); i++)
	{
		int v1 = up[i].second.first;
		int v2 = up[i].second.second;
		int cost = up[i].first;

		if (!merge(v1, v2)) continue;
		if (cost == 0) cnt1++;
		until1++;
		if (until1 == m) break;
	}

	for (int i = 0; i <= n; i++)
	{
		parent[i] = -1;
	}

	int cnt2 = 0, until2 = 0;
	for (int i = 0; i < down.size(); i++)
	{
		int v1 = down[i].second.first;
		int v2 = down[i].second.second;
		int cost = down[i].first;

		if (!merge(v1, v2)) continue;
		if (cost == 0) cnt2++;
		until2++;
		if (until2 == m) break;
	}
	printf("%d", cnt1*cnt1 - cnt2 * cnt2);
}
 

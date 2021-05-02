#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> pii;
typedef pair<pair<int, int>, pair<int, int>> piii;
int n, k;

vector<pii>adj;
piii arr[100005];

bool sortX(piii x, piii y) {
	if (x.first.second == y.first.second) {
		if (x.second.first == y.second.first)
			return x.second.second < y.second.second;
		else return x.second.first < y.second.first;
	}
	return x.first.second < y.first.second;
}

bool sortY(piii x, piii y) {
	if (x.second.first == y.second.first) {
		if (x.first.second == y.first.second)
			return x.second.second < y.second.second;
		else return y.first.second < y.first.second;
	}
	return x.second.first < y.second.first;
}

bool sortZ(piii x, piii y) {
	if (x.second.second == y.second.second) {
		if (x.first.second == y.first.second)
			return x.second.first < y.second.first;
		else return y.first.second < y.first.second;
	}
	return x.second.second < y.second.second;
}

vector<int>uf(100005, -1);
int find(int a) {
	if (uf[a] < 0)return a;
	return uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y) return 0;

	if (uf[x] == uf[y]) uf[x]--;
	if (uf[x] < uf[y]) uf[y] = x;
	else uf[x] = y;

	return 1;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		arr[i].first.first = i;
		scanf("%d%d%d", &arr[i].first.second, &arr[i].second.first, &arr[i].second.second);
	}

	//sortX
	sort(arr, arr + n, sortX);
	for (int i = 0; i < n - 1; i++)
	{
		adj.push_back({ arr[i + 1].first.second - arr[i].first.second, {arr[i].first.first, arr[i + 1].first.first } });
	}

	sort(arr, arr + n, sortY);
	for (int i = 0; i < n - 1; i++)
	{
		adj.push_back({ arr[i + 1].second.first - arr[i].second.first, {arr[i].first.first, arr[i + 1].first.first } });
	}

	sort(arr, arr + n, sortZ);
	for (int i = 0; i < n - 1; i++)
	{
		adj.push_back({ arr[i + 1].second.second - arr[i].second.second, {arr[i].first.first, arr[i + 1].first.first } });
	}

	sort(adj.begin(), adj.end());

	int cnt = 0, weight = 0;
	for (int i = 0; i < adj.size(); i++)
	{
		int cost = adj[i].first;
		int u = adj[i].second.first;
		int v = adj[i].second.second;

		if (!merge(u, v)) continue;

		weight += cost;
		cnt++;
		if (cnt == n - 1) break;
	}

	printf("%d", weight);
}

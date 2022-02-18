#include<iostream>
#include<algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>>v;
vector<int>ans, result, time, check;
queue<int>q;

int main() {
	scanf("%d", &n);
	v.resize(n + 1);
	time.resize(n + 1);
	check.resize(n + 1);
	result.resize(n + 1);

	for (int i = 1; i <= n; i++){
		scanf("%d",&time[i]);

		while (1) {
			int x;
			scanf("%d", &x);
			if (x == -1) break;
			v[x].push_back(i);
			check[i]++;
		}
	}

	for (int i = 1; i <= n; i++)
		if (check[i] == 0) {
			q.push(i);
			result[i] = time[i];
		}

	for (int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();

		for (int j = 0; j < v[x].size(); j++) {
			int y = v[x][j];
				result[y] = max(result[y], result[x] + time[y]);

			if (--check[y] == 0)
				q.push(y);
		}
	}

	for (int i = 1; i <= n; i++)
		printf("%d\n", result[i]);

	return 0;
}

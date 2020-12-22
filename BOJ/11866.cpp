#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
vector<int>ans;
queue<int>q;
int main() {
	scanf("%d%d", &n, &k);

	for (int i = 1; i <= n; i++)
		q.push(i);

	while (!q.empty()) {
		for (int i = 1; i < k; i++)
		{
			q.push(q.front());
			q.pop();
		}
		ans.push_back(q.front());
		q.pop();
	}

	printf("<");
	for (int i = 0; i < n; i++)
	{
		printf("%d", ans[i]);
		if (i < n - 1) printf(", ");
	}
	printf(">");
}

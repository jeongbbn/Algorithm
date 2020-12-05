#include<iostream>
#include<algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define red 1
#define blue 2
using namespace std;

typedef struct nodes {
	int check;
	int color;
	nodes() {
		this->check = 0;
		this->color = 0;
	}
}p;

vector<vector<int>>arr;
p node[20005];
int k, v, e;

int bfs(int sx) {
	queue<int>q;
	node[sx].check = 1;
	node[sx].color = red;
	q.push(sx);

	while (!q.empty()) {
		int x = q.front();
		int flag = node[x].color;
		q.pop();

		for (int i = 0; i < arr[x].size(); i++) {
			int y = arr[x][i];

			if (node[y].check == 0) {
				q.push(y);
				node[y].check = 1;
				if (flag == red) node[y].color = blue;
				else node[y].color = red;
			}
			
			if (node[y].check == 1) {
				if ((flag == red && node[y].color == red) || 
					(flag == blue && node[y].color == blue)) return -1;
			}
		}
	}
	return 1;
}

int main() {
	scanf("%d", &k);
	for (int i = 0; i < k; i++){
		scanf("%d %d", &v, &e);
		arr.resize(v + 1);

		for (int j = 0; j < e; j++){
			int a, b;
			scanf("%d %d",&a, &b);
			if (a != b) {
				arr[a].push_back(b);
				arr[b].push_back(a);
			}
		}

		int ans = 0;

		for (int i = 1; i <= v ; i++){
			if (node[i].check == 0) {
				ans = bfs(i);
				if (ans == -1) {
					printf("NO\n");
					break;
				}
			}
		}
		if (ans == 1) printf("YES\n");

		memset(node, 0, sizeof(node));
		arr.clear();
	}
	return 0;
}

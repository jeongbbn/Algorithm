#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

typedef struct {
	int name;
	int idx;
	int score;
}node;
int n, m;
node title[105];

bool cmp(node a, node b) {
	if (a.score == b.score) {
		return a.idx < b.idx;
	}
	return a.score < b.score;
}

bool cmp1(node a, node b) {
	return a.name < b.name;
}

int score[105];


int main() {
	scanf("%d%d", &n, &m);

	int p = 0;
	for (int i = 0; i < m; i++)
	{
		int a;
		scanf("%d", &a);

		score[a]++;

		//중복 확인
		bool flag = 0;
		for (int i = 0; i < p; i++)
		{
			if (title[i].name == a) {
				title[i].score = score[a];
				flag = 1;
				break;
			}
		}
		if (flag) continue;

		//비어있는 경우
		if (p < n) {
			title[p++] = { a,i,score[a] };
		}
		else {
			sort(title, title + p, cmp);

			//교체
			score[title[0].name] = 0;
			title[0] = { a,i,score[a] };
		}
	}

	sort(title, title + p, cmp1);
	for (int i = 0; i < p; i++)
	{
		printf("%d ", title[i].name);
	}
}

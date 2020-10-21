#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;

typedef struct {
	int a;
	int b;
	int c;
}node;

int A, B, C;
bool visit[205][205][205];
queue<node>q;
vector<int>ans;

void bfs() {

	while (!q.empty()) {

		int a, b, c;
		a = q.front().a;
		b = q.front().b;
		c = q.front().c;
		q.pop();

		if (visit[a][b][c]) continue;
		visit[a][b][c] = 1;

		if (a == 0) ans.push_back(c);

		//c->a
		if (c + a - A > 0) q.push({ A , b, c + a - A }); 
		else q.push({ a + c,b,0 });

		//c->b
		if (c + b - B > 0) q.push({ a , B, c + b - B });
		else q.push({ a,b + c,0 });

		//a->b
		if (b + a - B > 0) q.push({ b + a - B,B,c });
		else q.push({ 0,b + a,c });

		//a->c
		if (c + a - C > 0) q.push({ c + a - C , b, C });
		else q.push({ 0,b,c + a });

		//b->a
		if (b + a - A > 0) q.push({ A , b + a - A, c });
		else q.push({ a + b,0,c });

		//b->c
		if (c + b - C > 0) q.push({ a , c + b - C, C });
		else q.push({ a,0,b + c });
	}
}

int main() {
	scanf("%d%d%d", &A, &B, &C);

	q.push({ 0,0,C });
	bfs();

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}
}

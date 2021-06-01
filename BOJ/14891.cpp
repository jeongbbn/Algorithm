#include <iostream>
#include <vector>
#include <deque>
using namespace std;

deque<int>d[5];
int flag[5], visit[5];
void func(int idx, int r) {
	flag[idx] = r;
	visit[idx] = 1;
	if (idx > 1 && d[idx][2] != d[idx - 1][6]) {
		if (visit[idx - 1]) return;
		flag[idx - 1] = r * -1;
		func(idx - 1, r*-1);
	}
	else if (idx < 4 && d[idx][6] != d[idx + 1][2]) {
		if (visit[idx - 1]) return;
		flag[idx + 1] = r * -1;
		func(idx + 1, r*-1);
	}
}


int main() {
	for (int i = 1; i <= 4; i++)
	{
		for (int i = 0; i < 8; i++)
		{
			int a;
			scanf("%1d", a);
			d[i].push_back(a);
		}
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		func(a, b);
		
		for (int i = 1; i <= 4; i++)
		{
			if (flag[i] == 0) continue;
			else if (flag[i] == 1) {
				int x = d[i].back();
				d[i].pop_back();
				d[i].push_front(x);
			}
			else {
					int x = d[i].front();
					d[i].pop_front();
					d[i].push_back(x);
			}
		}

		for (int i = 1; i <= 4; i++)
		{
			visit[i] = 0;
			flag[i] = 0;
		}

	}

	int sum = 0;
	for (int i = 1; i <= 4; i++) {
		if(d[i].front()
		sum += (1 < i - 1);
	}
}

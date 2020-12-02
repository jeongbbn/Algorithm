#include <iostream>
#include <deque>
using namespace std;

int n, m, cnt;
int main() {
	scanf("%d%d", &n, &m);
	deque<int>dqf, dqb;
	for (int i = 1; i <= n; i++)
		dqf.push_back(i);
	for (int i = 0; i < m; i++)
	{
		dqb = dqf;
		int a,fcnt=0, bcnt=0;
		scanf("%d", &a);

		while (dqf.front() != a) {
			int temp = dqf.front();
			dqf.pop_front();
			dqf.push_back(temp);
			fcnt++;
		}
		dqf.pop_front();

		while (dqb.front() != a) {
			int temp = dqb.back();
			dqb.pop_back();
			dqb.push_front(temp);
			bcnt++;
		}
		dqb.pop_front();

		if (bcnt < fcnt) {
			cnt += bcnt;
			dqf = dqb;
		}
		else cnt += fcnt;
	}
	printf("%d", cnt);
}

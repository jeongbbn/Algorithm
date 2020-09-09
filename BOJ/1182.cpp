#include <iostream>
#include <algorithm>
using namespace std;

int n, s, arr[21], cnt;
bool visit[21];
void f(int p, int sum) {
	if (sum == s) cnt++;
	if (p == n) return;

	for (int i = p; i < n; i++)
	{
		if (!visit[i]) {
			visit[i] = 1;
			f(p + 1,sum+arr[i]);
			visit[i] = 0;
		}
	}
}

int main() {
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	f(0,0);
	if (s==0 && cnt!=0)
		printf("%d", cnt-1);
	else 
		printf("%d", cnt);
}


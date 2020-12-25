#include <iostream>
#include <stack>
using namespace std;

int n, height[500'001], ans[500'001];
stack<int>s;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &height[i]);

	for (int i = n; i > 1; i--) {
		if (height[i] < height[i - 1]) {
			ans[i] = i - 1;

			while (!s.empty()) {
				if (height[s.top()] < height[i - 1]) {
					ans[s.top()] = i - 1;
					s.pop();
				}
				else break;
			}
		}
		else {
			s.push(i);
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
}

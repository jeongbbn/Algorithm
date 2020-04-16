#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<math.h>
#include<map>
#include <string>
using namespace std;
#define INF 1e7
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;


priority_queue<int, vector<int>, greater<int>>minh;
priority_queue<int, vector<int>>maxh;
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {

		int a;
		scanf("%d", &a);

		if (maxh.empty()) {
			maxh.push(a);
		}

		else if (maxh.size() == minh.size())	maxh.push(a);
		else  minh.push(a);

		if (!maxh.empty() && !minh.empty()) {
			if (minh.top() < maxh.top()) {
				int tmp1 = maxh.top();
				int tmp2 = minh.top();

				maxh.pop();
				minh.pop();

				maxh.push(tmp2);
				minh.push(tmp1);
			}
		}

		printf("%d\n", maxh.top());
	}

}

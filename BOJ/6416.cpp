#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<map>
#include <string>
#include <set>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int tc;
int main() {
	while (1) {
		set<int>s, root;
		tc++;
		int a, b;
		int cnt = 0;
		scanf("%d%d", &a, &b);
		if (a == -1 && b == -1) break;
		if (a == 0 && b == 0) {
			printf("Case %d is a tree.\n", tc);
			continue;
		}

		bool flag=false;
		if (a == b) flag = true;
		cnt++;
		s.insert(a);
		s.insert(b);
		root.insert(b);

		while (1) {
			int c, d;
			scanf("%d%d", &c, &d);
			if (c == 0 && d == 0) break;
			if(c==d) flag=true;
			s.insert(c);
			s.insert(d);
			root.insert(d);
			cnt++;
		}

		int size = s.size();
		int rsize = root.size();
		if (size - 1 == cnt && !flag && size-rsize == 1) {
			printf("Case %d is a tree.\n", tc); continue;
		}
		printf("Case %d is not a tree.\n", tc);
	}


}

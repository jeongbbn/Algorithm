#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<map>
#include <string>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, m, k;
char arr[1005][1005];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
queue<pi>q;
queue<pi>jq;

bool outrange(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>m - 1) return 1;
	return 0;
}


int main() {
	while (scanf("%d", &n)!=EOF) {
		int arr[100005] = { 0, };
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		vector<int>v;
		v.push_back(arr[0]);
		int len = 1;
		for (int i = 1; i < n; i++)
		{
			if(v.back() < arr[i]) {
				v.push_back(arr[i]);
				len++;
			}
			else {
				auto t = lower_bound(v.begin(), v.end(),arr[i]);
				*t = arr[i];
			}
		}

		printf("%d\n", len);

	}
	
}

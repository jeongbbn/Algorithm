#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int,pair<int, int>>pii;

int n;
vector<pii>arr;
int chk[105];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a,&b,&c);
		arr.push_back({ c,{a,b} });
	}

	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());

	int cnt = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (cnt == 3) break;
		if (chk[arr[i].second.first] >= 2) continue;

		chk[arr[i].second.first]++;
		cnt++;
		printf("%d %d\n", arr[i].second.first, arr[i].second.second);
	}

}

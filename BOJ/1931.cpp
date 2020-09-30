#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,x,y,cnt=1,flag;
vector<pair<int, int>>v; // pair<int,int>s[1001] 

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		v.push_back({ y,x });
	}
	sort(v.begin(), v.end());
	int len = v.size();
	flag = v[0].first;
	for (int i = 1; i < len; i++)
	{
		if (v[i].second >= flag) {
			cnt++;
			flag = v[i].first;
		}
	}
	printf("%d", cnt);
}

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int idx[10005],arr[10005], place[10005];
/*
2 4 1
4 5 1

	idx[0] = 2  arr[4] = 1 ->>> 1번위치에 있는건 4다. place[1] = 4
	idx[1] = 4  arr[5] = 2   place[2] = 5
	idx[2] = 1  arr[1] = 3   place[3] = 1

	>>idx를 for로 순회해서 arr[idx[i]] 이런식으로 사용할 예정
*/


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &idx[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &place[i]);
		arr[place[i]] = i;
	}

	vector<int>v;
	vector<pi>ans;
	v.push_back(arr[idx[0]]);
	ans.push_back({ 0,arr[idx[0]] });

	int len = 1;
	for (int i = 1; i < n; i++)
	{
		int x = arr[idx[i]];
		if (v.back() < x) { 
			v.push_back(x);

			len++;
			ans.push_back({ v.end() - v.begin() - 1,x }); //v.end()는 끝+1이라서 -1를 해줘야된다.
		}
		else {
			auto p = lower_bound(v.begin(), v.end(), x);
			*p = x;

			ans.push_back({ p - v.begin(), x }); //반면 lower_bound는 현재 위치를 가리키고 있기 때문에
			//바로 -v.begin()해주면 인덱스를 알 수 있다. 
		}
	}

	printf("%d\n", len);

	vector<int>ANS;
	int k = len - 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (k == ans[i].first) {
			ANS.push_back(place[ans[i].second]);
			k--;
		}
	}

	sort(ANS.begin(), ANS.end());
	for (int i = 0; i < ANS.size(); i++)
	{
		printf("%d ", ANS[i]);
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

typedef struct {
	int gold;
	int silver;
	int bronze;
	int idx;
}p;


bool comp(p a, p b) {

	if (a.gold == b.gold) {
		if (a.silver == b.silver) {
			return a.bronze > b.bronze;
		}
		else return a.silver > b.silver;
	}
	else return a.gold > b.gold;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	p ans;
	p arr[1005];
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d",&arr[i].idx, &arr[i].gold, &arr[i].silver, &arr[i].bronze);
		if (arr[i].idx == k) {
			ans.gold = arr[i].gold;
			ans.silver = arr[i].silver;
			ans.bronze = arr[i].bronze;
		}
	}

	sort(arr, arr + n, comp);

	for (int i = 0; i < n; i++)
	{
		if (arr[i].gold == ans.gold && arr[i].silver == ans.silver
			&& arr[i].bronze == ans.bronze) {
			printf("%d", i + 1); 
			break;
		}
	}
}

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<double, int>pi;
typedef pair<double, pair<int, int>>pii;
typedef long long ll;

int n, ans;
vector<int>mp, mm, wm, wp;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a < 0) mm.push_back(a);
		else mp.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a < 0) wm.push_back(a);
		else wp.push_back(a);
	}

	sort(mm.begin(), mm.end());
	sort(wm.begin(), wm.end());
	reverse(wm.begin(), wm.end());
	reverse(mm.begin(), mm.end());

	sort(mp.begin(), mp.end());
	sort(wp.begin(), wp.end());

	int i = 0, j = 0;
	while (i < wp.size() && j < mm.size()) {
		if (wp[i] < abs(mm[j])) { i++; j++; ans++; }
		else j++;
	}

	i = 0; j = 0;
	while (i < mp.size() && j < wm.size()) {
		if (mp[i] < abs(wm[j])) { i++; j++; ans++;}
		else j++;
	}
	printf("%d", ans);
}

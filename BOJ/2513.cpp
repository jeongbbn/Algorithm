#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

vector<pair<int, int>>v;
int main() {
	int n, k, s;
	scanf("%d%d%d", &n, &k, &s);

	int left = 0, right = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		v.push_back({ a - s,b }); 
	}
	sort(v.begin(), v.end());

	int road = 0, i = 0;
	bool flag = 0;

	while (v[i].first < 0) {  
		road += abs(v[i].first) * 2;

		if (v[i].second > k)  continue; 

		int carry = k;
		while (v[i].second <= carry) { 
			carry += v[i].second;

			i++; 
			if (i >= n || v[i].first > 0) { flag = 1; break; }
			
		} 
		if (flag) break;
	}

	i = n - 1;
	flag = 0;
	while (v[i].first > 0) {
		v[i].second -= k;
		road += abs(v[i].first) * 2;

		if (v[i].second > 0) continue;

		while (v[i].second <= 0) {
			int leftover = -v[i].second;
			i--;
			if (i < 0 || v[i].first < 0) { flag = 1; break; }
			v[i].second = v[i].second - leftover;
		}
		if (flag) break;
	}

	printf("%d", road);
}

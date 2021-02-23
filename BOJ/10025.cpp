#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int>pi;

int n, k, st, en, cnt, ans;
pi arr[100005];
vector<int>v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].second >> arr[i].first;
		if (arr[i].first - k >= 0) v.push_back(arr[i].first - k);
		else v.push_back(arr[i].first);

		if (arr[i].first + k < 1000001) v.push_back(arr[i].first + k);
		else v.push_back(arr[i].first);
	}

	sort(v.begin(), v.end());
	sort(arr, arr + n);

	int i = 0;
	while (i < v.size()) {
		if (en < n && arr[en].first <= v[i] + k) {
			cnt += arr[en++].second;
		}

		else if (arr[st].first < v[i] - k) {
			cnt -= arr[st++].second;
		}

		else {
			ans = max(ans, cnt);
			i++;
		}
	}

	cout << ans;
}

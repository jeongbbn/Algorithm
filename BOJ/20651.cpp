#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int>pi;

int n, arr[105], ans;
int cnt[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	ans = n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {
		int sum = arr[i];
		cnt[arr[i]]++;
		for (int j = i + 1; j < n; j++)
		{
			cnt[arr[j]]++;
			sum += arr[j]; 
			if (sum % (j - i + 1) != 0) continue;
			if (cnt[sum / (j - i + 1)] > 0) ans++;
		}
		for (int j = i + 1; j < n; j++) cnt[arr[j]]--;
		cnt[arr[i]]--;
	}
	cout << ans << "\n";
}

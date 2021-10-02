#include<bits/stdc++.h>
using namespace std;

int n, q;
vector<int>arr;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int x; cin >> x;
		cout << binary_search(arr.begin(), arr.end(), x) << "\n";
	}
}

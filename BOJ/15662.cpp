#include <bits/stdc++.h>
using namespace std;
#define MAXX 8;
#define LEFT 6;
#define RIGHT 2;

int t, k;
vector<string>v;
vector<int>idx;

int rangeOfIdx(int x) {
	if (x < 0) x = x % 8 + 8;
	else if (x >= 8) x = x % 8;
	return x;
}

void rotate(int now, int dir) {
	int bfr_dir1 = dir;
	for (int i = now; i + 1 < v.size(); i++)
	{
		int A = rangeOfIdx(idx[i] + 2 - bfr_dir1);
		int B = rangeOfIdx(idx[i + 1] + 6);

		if (v[i][A] == v[i + 1][B]) break;
		bfr_dir1 *= -1;
		idx[i + 1] = rangeOfIdx(idx[i + 1] + bfr_dir1);
	}

	int bfr_dir2 = dir;
	for (int i = now; i - 1 >= 0; i--)
	{
		int A = rangeOfIdx(idx[i] + 6 - bfr_dir2);
		int B = rangeOfIdx(idx[i - 1] + 2);

		if (v[i][A] == v[i - 1][B]) break;
		bfr_dir2 *= -1;
		idx[i - 1] = rangeOfIdx(idx[i - 1] + bfr_dir2);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string a; cin >> a;
		v.push_back(a);
		idx.push_back(0);
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		b *= -1;
		a -= 1;
		idx[a] = rangeOfIdx(idx[a] + b);
		rotate(a, b);
	}

	int ans = 0;
	for (int i = 0; i < v.size(); i++)
		if (v[i][idx[i]] == '1') ans++;
	cout << ans;
}

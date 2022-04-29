#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		int n, zero = 0; cin >> n;
		if (n == 0) break;

		vector<int>v;
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			if (a == 0) zero++; //0이 맨 앞에 있는 경우 따로 처리를 해야한다.
			v.push_back(a);
		}

		sort(v.begin(), v.end());

		//0이 하나인 경우에는 0 1 2 3 → 2 1 0 3으로 교체하여,
		//만들어지는 두 개의 숫자에 대해 어떠한 것도 첫 시작이 0이 아니도록 한다.
		if (zero == 1) swap(v[0], v[2]);

		//0이 두 개 이상인 경우에는, 0 0 0 1 2 3 이므로, zero개 이후에 있는 숫자와 바꾼다.
		if (zero >= 2) {
			swap(v[0], v[zero]);
			swap(v[1], v[zero + 1]);
		}

		string l = "", r = "";
		for (int i = 0; i < v.size(); i++)
		{
			//0을 추가하는 경우에도 쉽게 처리하도록 문자열로 고쳐준다
			string now = to_string(v[i]);
			if (i % 2 == 0) l += now;
			else r += now;
		}
		//문자열을 숫자로 변환하여 답을 구한다.
		cout << stoi(l) + stoi(r) << "\n";
	}
}

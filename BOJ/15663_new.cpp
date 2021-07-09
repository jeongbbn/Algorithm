#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pi;
#define INF 1e9 + 7


int n, m, bfr;
vector<int>v, selected;

void P(int cnt, int visited) {
	if (cnt == m) {
		for (int i = 0; i < selected.size(); i++) {
			cout << selected[i] << " ";
		}
		cout << "\n";
		return;
	}

	int bfr = 0; 
	/*
		1 1 5 5 5 이렇게 있을 때,
		i=2이 되면 15_을 본 다음에 다시 1_ _로 돌아오고 i=3을 보게되는데,
		둘 다 똑같이 5니까 중복되게 된다. => bfr 변수에 넣어주고 판단한다.
	*/
	for (int i = 0; i < n; i++)
	{
		if (visited & (1 << i)) continue;
		if (bfr == v[i]) continue;
		bfr = v[i];
		selected.push_back(v[i]);
		P(cnt + 1, visited | (1 << i));
		selected.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());
	P(0, 0);
}

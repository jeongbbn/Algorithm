#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pi;
#define INF 1e9
#define MAX 100005
#define K 18

/*
    자신보다 x는 작은데 y는 큰 경우에 교차 간선이 생기게 된다.
    따라서 우선 x에 대해서 정렬하고, 
    인덱스 트리에 y에 대하여 개수(+1)를 넣어준다음,
    부분합을 구해 몇 개있는지 개수를 세어나가면 된다.
*/

int n, m;
ll ans;
vector<pi>v;
vector<int>tree;

void update(int i, int diff) {
	while (i < tree.size()) {
		tree[i] += diff;
		i += (i & -i);
	}
}

int sum(int i) {
	int tmp = 0;
	while (i > 0) {
		tmp += tree[i];
		i -= (i & -i);
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	tree.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		int a = v[i].first;
		int b = v[i].second;

		ans += sum(n) - sum(b);
		update(b, 1);
	}

	cout << ans;
	return 0;
}

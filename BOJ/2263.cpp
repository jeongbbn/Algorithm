#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<map>
#include <string>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n;
int in[100005], post[100005];
void findpre(int lst, int len, int rst, int ren) {

	if (lst > len || rst > ren) return;

	int root = post[ren];
	printf("%d ", root);

	findpre(lst, in[root] - 1, rst, rst + in[root] - lst - 1);
	findpre(in[root] + 1, len, rst + in[root] - lst, ren - 1);
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		in[a] = i;
	}

	for (int i = 0; i < n; i++)
		scanf("%d", &post[i]);

	findpre(0,n-1,0,n-1);
}

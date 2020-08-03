#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define INF 1e9;

int t, n;
int arr[45];

/*
	EX)
		3 2 7 6
	%2  1 0 1 0
	idx 0 1 0 1

	wrong[0]: 2 , wrong[1]: 2
	->wrong[0]==wrong[1]이면, swap을 통해 0 1 0 1으로 만들어 줄 수 있음

	3 2 5
	1 1 1 
	0 1 0

	wrong[1]: 3, wrong[0]: 0
	->swap 불가능
*/


int main() {
	scanf("%d", &t);
	while(t--){
		int wrong[2] = { 0, };
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);

			if (i % 2 != a % 2) wrong[a % 2]++;
		}
		
		if (wrong[0] == wrong[1]) printf("%d\n", wrong[0]);
		else printf("-1\n");
	}
}

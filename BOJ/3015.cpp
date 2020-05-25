#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, arr[500005];
int l[500005];
stack<pi>s;


/*
stack <item, 왼쪽에 있는 것들 중 같은 수의 갯수>

9
5 5 6 6 6 5 5 6 6

각 차례마다 stack에 들어가는 수
   (5,1) (6,0) (6,1) (6,2) (5,0) (5,1) (6,3)

0 1 2 1 2 1 2 5 4 => 18

*/
/*
풀이방법
top vs 넣어줄 값과 비교해서

넣어줄 값이 더 크면 스택을 비워준다 until top의 값이 넣어줄 값보다 클때까지
비워주면서 cnt를 세어줘서 l[i]에 저장

만약 작다면? 
그냥 스택에 넣어준다

같다면?
pop을 해주는데, 같은 수의 갯수를 세어줘서
pair로 저장한다

왜냐면
5 5 5 6 일 경우엔
스택은 5 6 이렇게 되는데 5는 사실 왼쪽에 있던 2개가 합쳐진 것이기 때문이다.

*/

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	s.push({ arr[0],0 });
	for (int i = 1; i < n; i++)
	{
		if (s.empty()) { s.push({ arr[i] ,0}); continue; }

		int same = 0, cnt = 0;
	
		while (!s.empty()) {
			if (s.top().first > arr[i]) { cnt++; break; }
			if (s.top().first == arr[i]) { same = 1; same += s.top().second; }
			//same = 1에서 시작해야한다. 왜냐하면 s.top()에 있는건
			//top에 있는 애의 왼쪽에 있던 것들 중 top이랑 같았던 것들의 갯수라
			//top은 포함되지않기 때문
			cnt += s.top().second; 
			cnt++;
			s.pop();
		}
		l[i] = cnt;
		s.push({ arr[i] ,same });
	}
		

	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += l[i];
	}

	printf("%lld", ans);
}

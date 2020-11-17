/*
백준 20159
동작 그만. 밑장 빼기냐?
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[100005];
int dp[100005];

int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	scanf("%d",&arr[i]);
if(i%2==0) dp[1]+=arr[i];
	}
	
    if(n%2==1)
	dp[1]+=arr[n];
	
	dp[2]=dp[1]-arr[n]+arr[1];
	
	for(int x=3; x<=n; x++){
		if(x%2==0){
			dp[x]=dp[x-2]+arr[x-1]-arr[x-2];
		}
		else{
			dp[x]=dp[x-2]-arr[x-1]+arr[x-2];
		}
	}
	cout<<*max_element(dp,dp+n+1);
	return 0;
}

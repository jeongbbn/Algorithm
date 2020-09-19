#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a,b,n,w,x,y;
int main() {
	scanf("%d%d%d%d", &a,&b,&n,&w);

	for(int i=1; i<n; i++){
    if(w-(a*i)==(n-i)*b) {
        if(x==0 && y==0){
               x=i; y=n-i;
            }
        else{
              printf("-1"); 
              return 0;
            }
        }
    }
    if(x==0 && y==0) printf("-1");
    else printf("%d %d",x,y);
 }

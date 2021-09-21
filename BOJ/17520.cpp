#include <iostream>
using namespace std;
#define MOD 16769023
typedef long long ll; 
int n;
ll pow[100005];
int main(){
    scanf("%d",&n);
    pow[0] = 1;
    for(ll i=1; i<=n/2+1; i++){
        pow[i] = (pow[i-1] * 2 ) % MOD;
    }
    int a = n/2;
    if(n%2==1) a++;
    printf("%lld", pow[a]);
}

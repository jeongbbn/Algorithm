/*
  프로그래머스 입국심사
*/

#include <string>
#include <vector>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;

long long solution(int n, vector<int> times) {
    ll answer = 0;
    
    sort(times.begin(),times.end());
    int m = times.size();
    
    ll st = 0, en = times[m-1] * n;
    
    while(st+1<en){
        ll mid = (st+en)/2;
        ll sum = 0;
        for(int i = 0; i<m; i++){
            sum += mid/times[i];
        }
        if(sum >= n) en = mid;
        else st = mid;
    }
   answer = en;
    
    return answer;
}

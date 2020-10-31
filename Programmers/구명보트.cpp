#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int n = people.size();
    int st=0; int en=n-1;    

    sort(people.begin(), people.end());
    
    for(int i=0; i<n; i++){
        if(limit<people[i]) {
            answer=(n-i);
            en=i - 1;
            break;
        }
    }
    while(st<en){
        if(people[st]+people[en]<=limit){
            st++;
            en--;
        }
        else{
            en--;
        }
        answer++;
    }
    if(st==en) answer++;
    return answer;
}

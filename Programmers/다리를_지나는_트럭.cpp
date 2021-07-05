#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int>q;
    int total = 0, p = 0;
    
    while(1){
        if(p==truck_weights.size()) {
            answer+= bridge_length;
            break;
        }
        answer++;
        if (q.size() >=bridge_length) {
            total-=q.front();
            q.pop();
        }
        
        if (total + truck_weights[p]<= weight){
            q.push(truck_weights[p]);
            total+=truck_weights[p++];
        }
        else{
            q.push(0);
        }
    }
    return answer;
}

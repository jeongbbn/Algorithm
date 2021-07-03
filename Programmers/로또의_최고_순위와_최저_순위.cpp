#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int high, low, cnt;
bool visited[50];

int returnResult(int n){
    if(n == 6) return 1;
    else if(n==5) return 2;
    else if(n==4) return 3;
    else if(n==3) return 4;
    else if(n==2) return 5;
    else return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    for(int j=0; j<lottos.size(); j++){
            if(lottos[j] == 0) cnt++;
    }
    
    vector<int> num;
    for(int i =0; i<win_nums.size(); i++){
        bool flag = 0;
        for(int j=0; j<lottos.size(); j++){
            if(win_nums[i] == lottos[j]) {
                low++;
                flag = 1;
            }
        }
        if(!flag) num.push_back(win_nums[i]);
    }
    
    high = low + min((int)num.size(), cnt);
    
    answer.push_back(returnResult(high));
    answer.push_back(returnResult(low));
    
    return answer;
}

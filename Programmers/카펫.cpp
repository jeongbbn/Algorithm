/*
프로그래머스 카펫
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int x=1;x*x<=yellow; x++){
        if(yellow%x!=0) continue;
        int n = (x + (yellow/x)) * 2 + 4;
        if(n==brown) {
            answer.push_back(yellow/x + 2);
            answer.push_back(x + 2);
            break;
        }
    }
    
    return answer;
}

#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    vector<int>cnt; //이름에 대한 선수의 수
    map<string,int>m; //이름과 idx를 맵핑
    
    for(int i=0; i<participant.size(); i++){
        m[participant[i]]++; 
    }
    
    for(int i=0; i<completion.size(); i++){
        m[completion[i]]--;
    }
    
    for(int i=0; i<participant.size(); i++){
        if(m[participant[i]]==1) {
            answer=participant[i];
            break;
        }
    }
    return answer;
}

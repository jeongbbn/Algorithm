/*
프로그래머스 베스트 앨범
해시+우선순위 큐
*/


#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int>pi;

map<string,int>m;
priority_queue<pi, vector<pi>>pq[105];
int cnt[105];
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    int p=0;
    for(int i=0; i<genres.size( ); i++){
        if(m.find(genres[i]) != m.end()) {
            int x = m[genres[i]];
            cnt[x]+=plays[i];
            pq[x].push({plays[i], -i});
        }
        else {
            m.insert({genres[i], p});
            cnt[p] = plays[i];
            pq[p++].push({plays[i], -i});
        }
    }
 
    for(int i=0; i<p; i++){
        int pos = max_element(cnt, cnt+p) - cnt;
        for(int j=0; j<2; j++){
            if(pq[pos].empty()) break;
            answer.push_back(-pq[pos].top().second);
            pq[pos].pop();
        }
        cnt[pos] = -1;
    }
    
    return answer;
}

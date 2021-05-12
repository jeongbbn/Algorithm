class Solution {
    typedef pair<int,int>pi;
    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    
        vector<pi>tmp, v;    
        for(int i=0;i<intervals.size(); i++){
            int l = intervals[i][0];
            int r = intervals[i][1];   
            v.push_back({l,r});
        }
        
        sort(v.begin(), v.end());
        
        
        int minn=v[0].first, maxx=v[0].second;
        
        for(int i=1;i<v.size(); i++){
            int l = v[i].first;
            int r = v[i].second;   
            
            if(maxx < l){
                tmp.push_back({minn, maxx});
                minn = l;
                maxx = r;
            }
            maxx= max(maxx,r);
        }
        tmp.push_back({minn, maxx});

        
        vector<vector<int>> ans;
        ans.resize(tmp.size());
        for(int i=0;i<tmp.size();i++){
            ans[i].resize(2);
            ans[i][0] = tmp[i].first;
            ans[i][1] = tmp[i].second;
        }
        
        return ans;
    }
};

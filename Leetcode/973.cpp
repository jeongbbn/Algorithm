class Solution {
    typedef long long ll;
    typedef pair<ll,ll>pl;
    typedef pair<ll,pl>pll;
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pll>v;
        for(int i=0; i<points.size(); i++){
            ll x = points[i][0];
            ll y = points[i][1];
            ll dist = x*x + y*y;
            v.push_back({dist, {x,y}});
        }
        
        sort(v.begin(), v.end());
        
        vector<vector<int>>ans;
        ans.resize(k);
        for(int i=0;i<k;i++)   {
            ans[i].push_back(v[i].second.first);
            ans[i].push_back(v[i].second.second);
        }
        return ans;
    }
};

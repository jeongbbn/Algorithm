/*
Leetcode
121.Best Time to Buy and Sell Stock
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int idx = prices.size();
        int ans = 0, maxx = 0;
        for(int i=idx-1; i>=0; i--){
            maxx = max(maxx, prices[i]);
            ans = max(ans, maxx-prices[i]);
        }
        return ans;
    }
};

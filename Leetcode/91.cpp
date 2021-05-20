class Solution {
public:
    int numDecodings(string s) {
        int dp[105] = {0,};
        
        int n = s.size();
        if(s[0] != '0') dp[0] = 1;
        for(int i=1;i<n;i++){
            if(s[i-1]=='1' || (s[i-1]=='2' && (s[i]<'7'))) {
                dp[i] += (i - 2 >= 0) ? dp[i-2] : 1; 
            }
            
            if(s[i] =='0') continue;
            dp[i] += dp[i-1];
        }
        return dp[n-1];
    }
};

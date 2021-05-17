/*
Leetcode
53. Maximum Subarray
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], sum = nums[0];
        for(int i=1;i<nums.size();i++){
            sum = max(sum+nums[i], nums[i]);
            ans = max(sum, ans);
        }
        return ans;
    }
};

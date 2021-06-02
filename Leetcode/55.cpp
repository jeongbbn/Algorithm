class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canVisit = 0;
        for(int x=0; x<nums.size(); x++){
            if(canVisit < x) return 0;
            canVisit = max(canVisit, nums[x] + x);
        }
        return 1;
    }
};

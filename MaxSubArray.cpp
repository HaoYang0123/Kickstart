class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, curRes = 0;
        for(int i = 0; i < nums.size(); ++i) {
            curRes += nums[i];
            if(curRes > res) res = curRes;
            if(curRes < 0) curRes = 0;
        }
        return res;
    }
};

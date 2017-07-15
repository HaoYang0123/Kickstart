class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); ++i) {
            hash[nums[i]] = i;
        }
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            int key = target - nums[i];
            auto ind = hash.find(key);
            if(ind == hash.end()) continue;
            if(ind->second == i) continue;
            int i2 = ind->second;
            if(i < i2) {
                res.push_back(i);
                res.push_back(i2);
                return res;
            }
            res.push_back(i2);
            res.push_back(i);
            return res;
        }
    }
};

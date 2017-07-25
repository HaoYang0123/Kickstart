class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }
    
    int search(vector<int> & nums, int start, int end, int target) {
        if(start > end) return -1;
        int mid = (start + end) >> 1;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > nums[start]) {
            if(nums[start] <= target && nums[mid] >= target) {
                return search(nums, start, mid - 1, target);
            }
            else {
                return search(nums, mid + 1, end, target);
            }
        }
        else if(nums[mid] < nums[start]) {
            if(nums[mid] <= target && nums[end] >= target) {
                return search(nums, mid + 1, end, target);
            }
            else {
                return search(nums, start, mid - 1, target);
            }
        }
        else {
            if(nums[end] != nums[mid]) {
                return search(nums, mid + 1, end, target);
            }
            else {
                int res = search(nums, start, mid - 1, target);
                if(res != -1) return res;
                return search(nums, mid + 1, end, target);
            }
        }
        return -1;
    }
};

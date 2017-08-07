class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }
    
    int search(vector<int> & nums, int start, int end, int target) {
        if(start > end) return -1;
        int mid = (start + end) >> 1;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > nums[start]) { //说明[start, mid]是升序的
            if(nums[start] <= target && nums[mid] >= target) {
                return search(nums, start, mid - 1, target); //如果target在左半部分，则查找左半部分
            }
            else {
                return search(nums, mid + 1, end, target); //否则，查找右半部分
            }
        }
        else if(nums[mid] < nums[start]) { //同样，这里说明[start,mid]中有拐点
            if(nums[mid] <= target && nums[end] >= target) {
                return search(nums, mid + 1, end, target);
            }
            else {
                return search(nums, start, mid - 1, target);
            }
        }
        else { //处理特殊情况，start==mid的情况，如果start==mid，那么会出现nums[mid]==nums[start]
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

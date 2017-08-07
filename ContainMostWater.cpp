/*
两个指针分别从左到右和从右到左遍历，当左指针高度小于右指针高度，说明水的容量受限于左指针（较低高度者），所以需要移动左指针，这样才可能得到更大的容量。
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n <= 1) return 0;
        int left = 0, right = n - 1;
        int maxArea = 0;
        while(left < right) {
            int tmpArea = min(height[left], height[right]) * (right - left);
            if(tmpArea > maxArea) maxArea = tmpArea;
            if(height[left] < height[right]) ++left;
            else --right;
        }
        return maxArea;
    }
};

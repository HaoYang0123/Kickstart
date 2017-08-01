class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int lastPos = n -1; //定义当前时刻可以到达的最近的一个点
        for(int i = n - 2; i >= 0; --i) {
            int target = nums[i] + i;
            if(target >= lastPos) lastPos = i; //如果当前点可以到达最近的点，说明可以从这个点到达终点(n-1)，并且将最近的点赋值给当前点
        }
        return (lastPos == 0);
    }
};

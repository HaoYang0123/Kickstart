/*
使用long long来保存结果，如果超过了int的表示范围（即不在[INT_MIN, INT_MAX]区间），则返回0.
*/
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        bool fu = false;
        if(x < 0) {
            fu = true;
            x = -x;
        }
        vector<int> bits;
        while(x != 0) {
            int b = x % 10;
            bits.push_back(b);
            x /= 10;
        }
        long long cur = 1;
        for(int i = bits.size() - 1; i >= 0; --i) {
            res += (long long)((long long)(bits[i]) * cur);
            cur *= (long long)10;
        }
        if(fu) res = -res;
        if(res > INT_MAX || res < INT_MIN) return 0;
        return (int)res;
    }
};

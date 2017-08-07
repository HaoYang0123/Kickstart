/class Solution {
public:
    double myPow(double x, int n) {
        bool isF = false;
        long long N = n;
        if(n < 0) {
            isF = true;
            if(n != INT_MIN) //防止n为int表示的最小值，那么直接-n会超过int表示范围，所以使用long long存储n最好。
                N = -n;
            else
                N = -((long long)n);
        }
        
        double res = 1.0;
        while(N) { //使用快速幂运算
            if(N & 1 == 1) {
                res *= x;
            }
            x *= x;
            N >>= 1;
        }
        if(isF) res = 1.0 / res; //如果是负指数，那么原始结果应该是其倒数
        return res;
    }
};

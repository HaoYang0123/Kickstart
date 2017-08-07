/*
解题详解：
判断回文，两种情况，回文长度是奇数，则判断当前i与i，i-1与i+1, i-2与i+2，是否相等；如果是偶数，则判断当前i与i+1，i-1与i+2，...，找到最长的回文
时间复杂度为O(n^2)，n为字符串的长度
*/
class Solution {
public:
    int getLenAround(const string &s, int left, int right) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return right - left - 1;
    }
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        int maxLen = 0;
        for(int i = 0; i < s.length(); ++i) {
            int len = getLenAround(s, i, i);
            int len2 = getLenAround(s, i, i + 1);
            int curMaxLen = max(len, len2);
            if(curMaxLen > maxLen) {
                maxLen = curMaxLen;
                start = i - (curMaxLen - 1) / 2;
                end = i + curMaxLen / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

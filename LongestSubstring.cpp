class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1) return s.length();
        string subStr = "";
        subStr += s[0];
        int maxLen = 1;
        for(int i = 1; i < s.length(); ++i) {
            auto ind = subStr.find(s[i]);
            if(ind == string::npos) {
                subStr += s[i];
            }
            else {
                int tmpLen = subStr.length();
                if(tmpLen > maxLen) maxLen = tmpLen;
                subStr = subStr.substr(ind + 1) + s[i];
            }
        }
        int tmpLen = subStr.length();
        if(tmpLen > maxLen) maxLen = tmpLen;
        return maxLen;
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '[' || s[i] == '(' || s[i] == '{') st.push(s[i]);
            else {
                if(st.empty()) return false;
                char tt = st.top();
                st.pop();
                if(s[i] == ')' && tt != '(') return false;
                if(s[i] == ']' && tt != '[') return false;
                if(s[i] == '}' && tt != '{') return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};

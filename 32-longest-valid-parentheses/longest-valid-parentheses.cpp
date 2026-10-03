class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (!st.empty() && s[st.top()] == '(') {
                    st.pop();
                } else {
                    st.push(i);  
                }
            }
        }

        if (st.empty()) return n;

        int ans = 0;
        int lastInterrupt = n;

        while (!st.empty()) {
            ans = max(ans, lastInterrupt - st.top() - 1);
            lastInterrupt = st.top();
            st.pop();
        }

        return max(ans, lastInterrupt);
    }
};
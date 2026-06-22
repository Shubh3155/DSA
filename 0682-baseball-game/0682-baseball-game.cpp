class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int> st;
        int scores = 0;
        for (string op : operations) {
            if (op == "D") {
                st.push(2 * st.top());
            } else if (op == "C") {
                st.pop();
            } else if (op == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a + b);
            } else {
                st.push(stoi(op));
            }
        }

        if (st.empty())
            return 0;
        while (!st.empty()) {
            scores += st.top();
            st.pop();
        }
        return scores;
    }
};
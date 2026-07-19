class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();

        vector<bool> ans;
        for (string str : strs) {
            int have = 0;
            int ex = 0;
            int temp = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '0') {
                    if (str[i] == '1') {
                        if (!have) {
                            if (!ex) {
                                if (!temp) {
                                    ans.push_back(false);
                                    goto end;
                                } else --temp;
                            } else --ex;
                        } else --have;
                    } else if (str[i] == '?') {
                        if (have > 0) { 
                            ++temp;
                            --have;
                        }
                    }
                } else {
                    if (str[i] == '0') {
                        ++have;
                    } else if (str[i] == '?') {
                        ++ex;
                    }
                }
            }

            if (have > 0) ans.push_back(false);
            else ans.push_back(true);
            // end: cout << have << " " << temp << " " << ex << endl;
            end:;
        }

        return ans;
    }
};
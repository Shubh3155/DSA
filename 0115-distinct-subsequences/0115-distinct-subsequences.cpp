class Solution {
public:
    long long solve(string &s, string &t, int i, int j,
                    vector<vector<long long>> &dp)
    {
        if (j == t.size())
            return 1;

        if (i == s.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] =
                solve(s, t, i + 1, j + 1, dp) +
                solve(s, t, i + 1, j, dp);
        }

        return dp[i][j] =
            solve(s, t, i + 1, j, dp);
    }

    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(
            s.size(), vector<long long>(t.size(), -1));

        return solve(s, t, 0, 0, dp);
    }
};
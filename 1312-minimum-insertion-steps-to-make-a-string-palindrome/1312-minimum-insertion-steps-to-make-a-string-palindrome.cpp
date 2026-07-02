class Solution {
public:
    int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp) {

        if (i == a.size() || j == b.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (a[i] == b[j])
            return dp[i][j] = 1 + solve(a, b, i + 1, j + 1, dp);

        return dp[i][j] = max(solve(a, b, i + 1, j, dp),
                              solve(a, b, i, j + 1, dp));
    }

    int minInsertions(string s) {

        string rev = s;
        reverse(rev.begin(), rev.end());

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int lps = solve(s, rev, 0, 0, dp);

        return n - lps;
    }
};
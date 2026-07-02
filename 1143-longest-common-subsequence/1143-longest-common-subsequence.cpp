class Solution {
public:
    int solve(string& a,  string& b, int i, int j, vector<vector<int>>& dp){
        int ans = 0;
        // base case
        if(i == a.size()){
            return 0;
        }
        if(j == b.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(a[i] == b[j]){
            ans = 1 + solve(a, b, i+1, j+1, dp);
        }
        else {
            ans = max(solve(a, b, i+1, j, dp), solve(a, b, i, j+1, dp));
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(), -1));
        return solve(text1, text2, 0, 0, dp);
    }
};
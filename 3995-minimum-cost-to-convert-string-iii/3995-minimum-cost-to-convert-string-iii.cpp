class Solution {
public:
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        int n = source.length();
        if(target.length() != n){
            return -1;
        }

        int num_rules = rules.size();
        vector<int> true_costs(num_rules);

        for(int i = 0; i < num_rules; i++){
            int stars = 0;
            for(char c : rules[i][0]){
                if(c == '*'){
                    stars++;
                }
            }
            true_costs[i] = costs[i] + stars;
        }
        long long INF = 1e18;
        vector<long long> dp(n+1, INF);
        dp[n] = 0;

        for(int i = n-1 ; i >=0 ; i--){
            if(source[i] == target[i]){
                dp[i] = dp[i+1];
            }
            for(int r = 0 ; r < num_rules; r++){
                int len = rules[r][0].length();
                if(i + len <= n){
                    bool match = true;

                    for(int j = 0 ; j < len ; j++){
                        if(target[i+j] != rules[r][1][j]){
                            match = false;
                            break;
                        }
                        if(rules[r][0][j] != '*' && source[i + j] !=rules[r][0][j]){
                            match = false;
                            break;
                        }
                    }
                    if(match && dp[i + len] != INF){
                        dp[i] = min(dp[i], true_costs[r] + dp[i+ len]);
                    }
                }
            }
        }
        return dp[0] == INF ? -1 : dp[0];
    }
};
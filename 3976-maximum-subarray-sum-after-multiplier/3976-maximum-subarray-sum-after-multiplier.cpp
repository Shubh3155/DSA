class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long max_disjoint = -1e18;
        if(n>1){
            auto kadane = [&](int start, int end){
                long long mx = -1e18, cur = 0;
                for(int i = start ; i <= end ; i++){
                    cur = max((long long)nums[i], cur + nums[i]);
                mx = max(mx , cur);
                }
                return mx; 
            };
            max_disjoint = max(kadane(1, n-1), kadane(0,n-2));
        }

        auto solve = [&](auto op){
            long long dp0 = nums[0];
            long long dp1 = op(nums[0]);
            long long dp2 = -1e18;
            long long maxSum = dp1;

            for(int i = 1 ; i < n ; i++){
                long long x = nums[i];
                long long mod_x = op(x);

                long long new_dp2 = max(dp1 + x, (dp2 == -1e18 ? (long long)-1e18 : dp2 + x));
                long long new_dp1 = max({mod_x, dp0 + mod_x, dp1 + mod_x});

                long long new_dp0 = max((long long)x, dp0 +x);

                dp0 = new_dp0;
                dp1 = new_dp1;
                dp2 = new_dp2;

                maxSum = max({maxSum, dp1, dp2});
            }
            return maxSum;
        };
        auto mult = [&](int x) { return (long long)x * k; };
        auto div = [&](int x){ return (long long)(x/k); };

        long long ans_mult = solve(mult);
        long long ans_div = solve(div);

        return max({ans_mult, ans_div, max_disjoint});
    }
};
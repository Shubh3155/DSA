class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(), nums.rend());
        long long totalSum = 0;

        for(int i = 0 ; i < k ; i++){
            long long currentMul = max(1, mul - i);
            totalSum += (long long)nums[i] * currentMul;
            
        }
        return totalSum;
    }
};
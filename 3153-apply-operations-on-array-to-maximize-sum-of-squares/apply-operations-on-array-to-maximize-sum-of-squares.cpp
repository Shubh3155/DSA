class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1'000'000'007;
        vector<int> bitCount(31, 0);

        for (int num : nums) {
            for (int bit = 0; bit < 31; ++bit) {
                if (num & (1 << bit)) {
                    ++bitCount[bit];
                }
            }
        }

        long long answer = 0;

        for (int i = 0; i < k; ++i) {
            long long value = 0;

            for (int bit = 0; bit < 31; ++bit) {
                if (bitCount[bit] > 0) {
                    value |= (1LL << bit);
                    --bitCount[bit];
                }
            }

            answer = (answer + value * value) % MOD;
        }

        return static_cast<int>(answer);
    }
};
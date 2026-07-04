// class Solution {
// public:
//     int maxValidPairSum(vector<int>& nums, int k) {
//         int maxi = 0;
//         for(int i = 0 ; i < nums.size() ; i++){
//             for(int j = 1 ; j < nums.size() ; j++){
//                 if(j - i >= k){
//                     int ans = nums[i] + nums[j];
//                     maxi = max(maxi, ans);
//                 }
//             }
//         }
//         return maxi;
//     }
// };

class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi = nums[0];
        int ans = INT_MIN;

        for (int j = k; j < n; j++) {
            maxi = max(maxi, nums[j - k]);
            ans = max(ans, maxi + nums[j]);
        }

        return ans;
    }
};
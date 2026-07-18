class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long peaks1 = n/2;
        long long ans1 = s;
        if(peaks1){
            ans1 = s + peaks1 * 1LL * m - (peaks1 - 1);
        }

        long long peaks2 = (n - 1)/2;
        long long ans2 = s + peaks2 * 1LL * (m - 1);

        return max(ans1, ans2);
    }
};
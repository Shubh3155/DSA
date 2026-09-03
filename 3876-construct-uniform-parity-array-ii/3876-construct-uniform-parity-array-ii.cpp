class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
    int min_val = *min_element(nums1.begin(), nums1.end());
        
    // If the minimum element is odd, we can always make the array uniform
    if (min_val % 2 != 0) {
        return true;
    }
        
        // If the minimum element is even, we cannot have ANY odd numbers
    for (int num : nums1) {
        if (num % 2 != 0) {
            return false;
        }
    }
        
        return true;
    }
};
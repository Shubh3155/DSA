class Solution {
public:
    int minMoves(vector<int>& nums) {
        int smallest = *min_element(nums.begin(), nums.end());
        int moves = 0;

        for (int x : nums) {
            moves += x - smallest;
        }

        return moves;
    }
};
class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, maxdepth = 0;

for (char ch : s) {
    if (ch == '(') {
        depth++;
        maxdepth = max(maxdepth, depth); // use max() to update
    } else if (ch == ')') {
        depth--;
    }
}
// return maxdepth outside the loop
return maxdepth;
        
    }
};
class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string left, mid, right;

        for(char c : s){
            if(c == y){
                left += c;
            }
            else if(c == x){
                right += c;
            }
            else {
                mid += c;
            }
        }
        return left + mid + right;
    }
};
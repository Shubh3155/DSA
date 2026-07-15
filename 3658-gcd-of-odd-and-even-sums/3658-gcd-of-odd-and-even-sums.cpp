class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 1;
        for(int i = 2 ; i <= n ; i++){
            sumOdd = sumOdd + 2;
            i++;
        }
        int sumEven = 2;
        for(int i = 2 ; i <= n ; i++){
            sumOdd = sumOdd + 2;
            i++;
        }
        return n;
    }
};
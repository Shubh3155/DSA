class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0;
        int ans = 0;
        int n = s.size();
        unordered_map <char,int>mp;

        for(int j = 0; j < n ; j++){
            //calculation
            mp[s[j]]++;
            //shrink the window 
            while(mp.size() == 3){
                ans += n - j;
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        return ans;
    }
};

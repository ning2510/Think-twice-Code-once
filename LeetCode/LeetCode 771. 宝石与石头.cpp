class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map <char, int> ss;
        for(auto &x : J) {
            ss[x]++;
        }
        int ans = 0;
        for(auto &x : S) {
            if(ss.count(x)) ans++;
        }
        return ans;
    }
};
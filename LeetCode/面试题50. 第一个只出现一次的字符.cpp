class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map <char, int> ss;
        queue <char> pp;
        char ans = ' ';
        for(auto x : s) {
            ss[x]++;
            pp.push(x);
        }
        while(!pp.empty()) {
            auto x = pp.front();
            pp.pop();
            if(ss[x] == 1) {
                ans = x;
                break;
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool isValid(string s) {
        unordered_map <char, int> ss;
        ss['('] = 1;
        ss[')'] = -1;
        ss['['] = 2;
        ss[']'] = -2;
        ss['{'] = 3;
        ss['}'] = -3;
        stack <int> pp;
        for(auto x : s) {
            if(ss[x] > 0) {
                pp.push(ss[x]);
            }
            else {
                if(!pp.empty() && pp.top() * -1 == ss[x]) pp.pop();
                else return false;
            }
        }
        return pp.empty();
    }
};
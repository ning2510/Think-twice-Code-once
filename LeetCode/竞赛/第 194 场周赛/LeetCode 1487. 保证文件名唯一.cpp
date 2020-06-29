class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map <string, int> ss;
        for(auto &x : names) {
            if(!ss.count(x)) {
                ss[x]++;
            }
            else {
                int m = ss[x];
                string p = x + '(' + to_string(m) + ')';
                while(ss.count(p)) {
                    m++;
                    p = x + '(' + to_string(m) + ')';
                }
                ss[x] = ++m;
                ss[p]++;
                x = p;
            }
        }
        return names;
    }
};
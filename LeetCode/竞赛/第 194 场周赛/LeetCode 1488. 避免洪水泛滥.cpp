class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set <int> ss;
        vector <int> ans(rains.size(), -1);
        map <int, int> pp;
        for(int i = 0; i < rains.size(); i++) {
            if(!rains[i]) {
                ss.insert(i);
            }
            else {
                if(pp.count(rains[i])) {
                    if(ss.empty()) return {};
                    auto it = ss.upper_bound(pp[rains[i]]);
                    if(it == ss.end()) return {};
                    ans[*it] = rains[i];
                    ss.erase(it);
                    pp[rains[i]] = i;
                }
                else pp[rains[i]] = i;
            }
        }
        for(auto it = ss.begin(); it != ss.end(); it++) {
            ans[*it] = 1;
        }
        return ans;
    }
};
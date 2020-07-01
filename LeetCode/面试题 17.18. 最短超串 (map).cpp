class Solution {
public:
    int js_min(unordered_map <int, int> &ss) {
        unordered_map <int, int>::iterator it;
        int minx = 0x3f3f3f3f;
        for(it = ss.begin(); it != ss.end(); it++) {
            minx = min(minx, it->second);
        }
        return minx;
    }

    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        unordered_map <int, int> ss;
        for(int i = 0; i < small.size(); i++) {
            ss[small[i]] = -1;
        }
        int ans = 0x3f3f3f3f, sum = 0, l = -1, r = -1;
        for(int i = 0; i < big.size(); i++) {
            if(ss.count(big[i])) {
                if(ss[big[i]] == -1) sum++;
                ss[big[i]] = i;
                if(sum == small.size()) {
                    int t = js_min(ss);
                    if(i - t + 1 < ans) {
                        ans = i - t + 1;
                        l = t;
                        r = i;
                    }
                }
            }
        }
        if(l == -1 && r == -1) return {};
        return {l, r};
    }
};
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector <vector<int>> ss;
        int q[500005];
        memset(q, 0, sizeof(q));
        int l = 0, r = -1, sum = 0;
        for(int i = 1; i <= target / 2 + 2; i++) {
            if(sum < target) {
                sum += i;
                q[++r] = i;
            }
            else {
                while(sum > target) {
                    sum -= q[l++];
                }
                if(sum == target) {
                    vector <int> p;
                    for(int j = l; j <= r; j++) {
                        p.push_back(q[j]);
                    }
                    ss.push_back(p);
                    sum -= q[l++];
                }
                sum += i;
                q[++r] = i;
            }
        }
        return ss;
    }
};
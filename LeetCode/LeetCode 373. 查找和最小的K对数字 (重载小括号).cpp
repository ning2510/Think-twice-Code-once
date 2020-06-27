class Solution {
public:
    struct cmp {
        bool operator () (pair <int, int> &a, pair <int, int> &b) {
            return a.first + a.second < b.first + b.second;
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue <pair <int, int>, vector <pair <int, int>>, cmp> ss;
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                if(ss.size() < k) ss.push({nums1[i], nums2[j]});
                else {
                    if(nums1[i] + nums2[j] < ss.top().first + ss.top().second) {
                        ss.pop();
                        ss.push({nums1[i], nums2[j]});
                    }
                }
            }
        }
        vector <vector <int>> ans;
        while(!ss.empty()) {
            ans.push_back({ss.top().first, ss.top().second});
            ss.pop();
        }
        return ans;
    }
};
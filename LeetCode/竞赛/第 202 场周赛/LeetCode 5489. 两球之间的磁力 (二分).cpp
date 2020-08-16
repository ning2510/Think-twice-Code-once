class Solution {
public:
    int judge(int mid, int m, vector<int>& position) {
        int n = position.size(), now = position[0], sum = 1;
        while(now < position[n - 1]) {
            auto t = lower_bound(position.begin(), position.end(), now + mid);
            if(t == position.end()) break;
            now = *t;
            sum++;
            if(sum >= m) return true;
        }
        return sum >= m;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int ans = -1, l = 0, r = 1e9 + 5;
        while(l <= r) {
            int mid = ((l ^ r) >> 1) + (l & r);
            if(judge(mid, m, position)) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};
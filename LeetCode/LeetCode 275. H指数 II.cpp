class Solution {
public:
    int judge(int mid, vector<int>& citations) {
        if(mid == 0) return 1;
        int m = citations.size() - mid;
        return citations[m] >= mid;
    }

    int hIndex(vector<int>& citations) {
        int ans = 0, l = 0, r = citations.size();
        if(!r) return ans;
        while(l <= r) {
            int mid = ((l ^ r) >> 1) + (l & r);
            if(judge(mid, citations)) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};
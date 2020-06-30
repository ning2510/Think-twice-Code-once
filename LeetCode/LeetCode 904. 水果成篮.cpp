class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int l = 0, r = 1, fir = tree[0], sec;
        int ans = 0, n = tree.size();
        while(r < n && tree[r] == fir) r++;
        if(r == n) return n;
        sec = tree[r++];
        while(r < n) {
            if(tree[r] != fir && tree[r] != sec) {
                ans = max(ans, r - l);
                fir = tree[r - 1];
                sec = tree[r];
                l = r - 1;
                while(tree[l - 1] == fir) l--;
            }
            r++;
        }
        return max(ans, r - l);
    }
};
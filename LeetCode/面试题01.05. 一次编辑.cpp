class Solution {
public:
    bool oneEditAway(string first, string second) {
        int n = first.size(), m = second.size();
        if(abs(n - m) > 1) return false;
        if(n == m) {
            int l = 0, r = 0, flag = 0;
            while(l < n && r < n) {
                if(first[l] != second[r]) {
                    if(flag) return false;
                    flag = 1;
                }
                l++;
                r++;
            }
            return true;
        }
        if(n < m) {
            string s = first;
            first = second;
            second = s;
            swap(n, m);
        }
        int l = 0, r = 0, flag = 0;
        while(l < n && r < m) {
            if(first[l] != second[r]) {
                if(flag) return false;
                l++;
                flag = 1;
            }
            else {
                l++;
                r++;
            }
        }
        return true;
    }
};
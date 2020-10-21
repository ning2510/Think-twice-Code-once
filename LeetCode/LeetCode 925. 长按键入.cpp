class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int l = 0, r = 0;
        while(l < name.size() && r < typed.size()) {
            int c = name[l];
            int cnt1 = 0, cnt2 = 0;
            while(name[l] == c) {
                cnt1++;
                l++;
            }
            while(typed[r] == c) {
                cnt2++;
                r++;
            }
            if(cnt2 == 0) return false;
            if(cnt2 < cnt1) return false;
        }
        if(l != name.size() || r != typed.size()) return false;
        return true;
    }
};
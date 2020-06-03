class Solution {
public:
    bool isUnique(string astr) {
        int x = 0;
        for(int i = 0; i < astr.size(); i++) {
            if(x & (1 << (astr[i] - 'a'))) return false;
            else x |= (1 << (astr[i] - 'a'));
        }
        return true;
    }
};
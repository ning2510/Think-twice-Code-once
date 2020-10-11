class Solution {
public:
    int flag;
    
    void js(string &a, string &b) {
        int n = a.size();
        int l = 0, r = n - 1;
        while(l < r && a[l] == b[r]) {
            l++;
            r--;
        }
        if((n % 2 == 1 && l == r) || (n % 2 == 0 && l == r + 1)) {
            flag = 1;
            return ;
        }
        int l1 = l, r1 = r;
        while(l1 < r1 && a[l1] == a[r1]) {
            l1++;
            r1--;
        }
        if((n % 2 == 1 && l1 == r1) || (n % 2 == 0 && l1 == r1 + 1)) {
            flag = 1;
            return ;
        }
        l1 = l;
        r1 = r;
        while(l1 < r1 && b[l1] == b[r1]) {
            l1++;
            r1--;
        }
        if((n % 2 == 1 && l1 == r1) || (n % 2 == 0 && l1 == r1 + 1)) {
            flag = 1;
            return ;
        }
    }
    
    bool checkPalindromeFormation(string a, string b) {
        int n = a.size();
        if(n == 1) return true;
        flag = 0;
        js(a, b);
        if(flag) return true;
        js(b, a);
        if(flag) return true;
        return false;
    }
};
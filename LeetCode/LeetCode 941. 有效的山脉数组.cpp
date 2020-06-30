class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3) return false;
        int l = 0, r = A.size() - 1;
        while(l < A.size() - 1 && A[l] < A[l + 1]) l++;
        while(r > 0 && A[r] < A[r - 1]) r--;
        if(l != r || l == 0 || r == A.size() - 1) return false;
        return true;
    }
};
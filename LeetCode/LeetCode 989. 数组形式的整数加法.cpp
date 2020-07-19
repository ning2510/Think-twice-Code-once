class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(), A.end());
        A[0] += K;
        for(int i = 0; i < A.size(); i++) {
            if(i != A.size() - 1) {
                A[i + 1] += A[i] / 10;
                A[i] %= 10;
            }
            else {
                int x = A[i] / 10;
                A[i] %= 10;
                if(x) A.push_back(x);
            }
        }
        reverse(A.begin(), A.end());
        return A;
    }
};
/*
通过 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]，我们发现 B[i] 就是 A[i] 左边所有元素的积 乘 A[i] 右边所有元素的积。
*/

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector <int> ss(n, 1);
        int now = 1;
        for(int i = 0; i < n; i++) {
            ss[i] = now;
            now *= a[i];
        }
        now = 1;
        for(int i = n - 1; i >= 0; i--) {
            ss[i] *= now;
            now *= a[i];
        }
        return ss;
    }
};
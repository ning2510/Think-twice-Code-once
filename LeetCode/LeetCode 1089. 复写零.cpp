class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size() - 1, count_zero = 0;
        for(int i = 0; i <= n - count_zero; i++) {
            if(arr[i] == 0) {
                if(i == n - count_zero) {
                    arr[n] = 0;
                    n--;
                    break;
                }
                count_zero++;
            }
        }
        n -= count_zero;
        for(int i = n; i >= 0; i--) {
            if(arr[i] == 0) {
                arr[i + count_zero] = 0;
                count_zero--;
                arr[i + count_zero] = 0;
            }
            else arr[i + count_zero] = arr[i];
        }
        return ;
    }
};
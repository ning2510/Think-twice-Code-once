/*************************************************************************
	> File Name: bbb.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月28日 星期二 10时09分07秒
 ************************************************************************/

class Solution {
    public:
    vector<int> singleNumbers(vector<int>& nums) {
        int x = 0;
        for(int i : nums) {
            x ^= i;
                    
        }
        int div = 1;
        while((div & x) == 0) { //找到x对应二进制的第一个1的位置，然后以这个位置1分组
            div <<= 1;
        }
        int a = 0, b = 0;
        for(int i : nums) {
            if(div & i) a ^= i; //这个位置是1为一组
            else b ^= i;    //这个位置不是1为一组
                    
        }
        return vector <int> {a, b};
            
    }

};


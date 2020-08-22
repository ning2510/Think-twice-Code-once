class Solution {
public:
    const int target = 24;
    const double eps = 1e-6;

    bool solve(vector<double>& ss) {
        int n = ss.size();
        if(!n) return false;
        if(n == 1) {
            return fabs(ss[0] - target) < eps;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                vector <double> now;
                for(int k = 0; k < n; k++) {
                    if(k != i && k != j) now.emplace_back(ss[k]);
                }
                for(int k = 0; k < 4; k++) {
                    if(k < 2 && i > j) continue;
                    if(k == 0) now.emplace_back(ss[i] + ss[j]);
                    else if(k == 1) now.emplace_back(ss[i] * ss[j]);
                    else if(k == 2) now.emplace_back(ss[i] - ss[j]);
                    else {
                        if(fabs(ss[j]) < eps) continue;
                        now.emplace_back(ss[i] / ss[j]);
                    }
                    if(solve(now)) return true;
                    now.pop_back();
                }
            }
        }
        return false;
    }

    /*
    static_cast常用来进行基本类型直接的转换，如char与int、int与float、enum与int之间；
    static_cast也可以转换用户自定义类型，但目标类型必须含有相应的构造函数；
    static_cast还可以转换对象的指针类型，但它不进行运行时类型检查，所以是不安全的；
    static_cast甚至可以把任何表达式都转换成void类型；
    satic_cast不能移除变量的const属性；
    static_cast进行的是简单粗暴的转换，所以其正确性完全由程序员自己保证。
    */

    bool judgePoint24(vector<int>& nums) {
        vector <double> ss;
        for(const auto &x : nums) {
            ss.emplace_back(static_cast<double>(x));
        }
        return solve(ss);
    }
};
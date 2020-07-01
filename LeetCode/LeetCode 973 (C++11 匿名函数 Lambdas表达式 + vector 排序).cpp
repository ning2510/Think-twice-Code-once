/*************************************************************************
	> File Name: bbb.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月27日 星期一 23时52分51秒
 ************************************************************************/

class Solution {
    public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
                sort(points.begin(), points.end(),[](auto &x, auto &y) {    //匿名函数 Lambdas表达式
                                                                                   return x[0] * x[0] + x[1] * x[1] < y[0] * y[0] + y[1] * y[1];
                                                                               });
                points.resize(K);
                return points;
            
    }

};

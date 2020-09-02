class Solution {
public:
    bool isNumber(string s) {
        auto i = s.find_first_not_of(' ');//第一个不是空格的位置
        if(i == s.npos)return false;
        auto j = s.find_last_not_of(' ');//最后一个不是空格的位置
        s = s.substr(i, j - i + 1);//去除首尾空格
        if(s.empty()) return false;

        auto k = s.find_first_of('E');
        if(k != s.npos)   s[k] = 'e';//大写转小写
  
        int pos = s.find('e');
        if(pos == s.npos) return judgeLeft(s);//没有e
        return judgeLeft(s.substr(0, pos)) && judgeRight(s.substr(pos + 1));
    }

    bool judgeLeft(string s) {
        if(s.empty()) return false;
        if(s[0] == '+' || s[0] == '-') s.erase(0, 1);
        bool flag = false;
        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) continue;
            //符号位只能在第一位
            if(s[i] == '.') {
                if(flag) return false;//有多个小数点，返回false
                flag = true;//记录已经有一个小数点
            }
            else return false;
        }
        return !s.empty() && s != ".";
    }

    bool judgeRight(string s) { 
        //cout << s << endl;
        if(s.empty()) return false;
        if(s[0] == '+' || s[0] == '-') s.erase(0, 1);
        //右边不能出现小数点，所以出现除符号位的非纯数字表示指数不合法
        for(int i = 0; i < s.size(); i++) {
            if(!isdigit(s[i])) return false;
        }
        return !s.empty();
    }
};
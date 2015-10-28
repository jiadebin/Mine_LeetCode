class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long n = numerator, d = denominator;       //用long long防止溢出，如n=INT_MIN, m=-1时，n/m=INT_MAX+1,溢出
        if(d==0)
            return "";
        if(n==0)
            return "0";
        string res;
        if(n<0){
            n*=-1;
            d*=-1;
        }
        if(d<0){
            res.push_back('-');     //string.push_back(char) 参数为char，不是string
            d*=-1;
        }
        res.append(to_string(n/d));     //注意std::to_string 函数的使用
        n%=d;
        if(n==0)
            return res;
        res.push_back('.');
        unordered_map<int, size_t> map;     //hash_map存储循环时的<n, 当前res.size()>
        while(n!=0){
            n*=10;
            auto au = map.emplace(n, res.size());   //注意emplace成员方法的使用，如果插入成功返回<iterator, true>，否则返回<iterator, false>；iterator指的是该key的迭代器
            if(au.second){  //插入成功，即没有循环小数
                res.append(to_string(n/d));
                n%=d;
            }
            else{   //有循环小数
                res.insert(au.first->second, "(");      //注意string的insert方法的使用，第一个参数为插入位置的迭代器，第二个参数为string
                res.push_back(')');
                break;
            }
        }
        return res;
    }
};
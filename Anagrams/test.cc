class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, int> map;
        vector<string> res;
        for(int i=0; i<strs.size(); ++i){
            string s = strs[i];
            sort(s.begin(), s.end());   //对每个string成员都按字母排序，便于判断是否为anagrams（即由相同字母组合而成的单词）
            if(map.find(s)!=map.end()) {    //unordered_map自带find方法
                string temp = strs[map[s]];
                if(find(res.begin(), res.end(), temp)==res.end())   //看res中是否已经插入了该模板
                    res.push_back(temp);
                res.push_back(strs[i]);
            } else {
                map.insert({s, i});
            }
        }
        return res;
    }
};
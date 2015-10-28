#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

int main()
{
    int arr[] = {5, 6, 1, 2, 8};
    set<int> st(arr, arr+5);        //set是rb_tree来实现的，会对元素进行自动排序,不允许重复元素
    auto it = st.begin();
    while(it!=st.end()){
        cout<<*it<<",";
        it++;
    }
    cout<<endl;
    auto res = st.insert(5);        //insert返回值是pair<iterator, bool> bool表示插入成功与否
    cout<<*(res.first)<<", "<<(res.second)<<endl;

    map<string, int> mp;        //rb_tree实现，会对元素根据key进行自动排序,不允许key重复
    mp.insert(pair<string, int>("ddd", 4));
    mp.insert(pair<string, int>("ccc", 3));
    mp.insert(pair<string, int>("aaa", 1));

    auto mit = mp.begin();
    while(mit != mp.end()){     //注意不能用 mit++ != end 作为条件，因为mit自增之后进入while就可能跳到end处了，导致输出出错
        cout<<mit->first<<mit->second<<",";
        mit++;
    }
    cout<<endl;
    int x=4;
    while(x++ != 5)
        cout<<x<<endl;
    return 0;
}

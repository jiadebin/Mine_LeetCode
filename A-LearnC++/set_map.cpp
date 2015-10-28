#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

int main()
{
    int arr[] = {5, 6, 1, 2, 8};
    set<int> st(arr, arr+5);
    auto it = st.begin();
    while(it!=st.end()){
        cout<<*it<<",";
        it++;
    }
    cout<<endl;
    auto res = st.insert(7);
    cout<<*(res.first)<<", "<<(res.second)<<endl;

    map<string, int> mp;
    mp.insert(pair<string, int>("aaa", 11));

    auto mit = mp.begin();
    while(mit != mp.end()){     //注意不能用mit++ != end这么写，因为这样进入while后mit已经被后移了，导致输出end值出错
        cout<<mit->first<<mit->second<<",";
        mit++;
    }
    cout<<endl;
    int x=4;
    while(x++ != 5)
        cout<<x<<endl;
    return 0;
}

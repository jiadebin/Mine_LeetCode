#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <cmath>

using namespace std;

/*
1、算法过程：
基数排序（以整形为例），将整形10进制按每位拆分，然后从低位到高位依次比较各个位。主要分为两个过程：
(1)分配，先从个位开始，根据位值(0-9)分别放到0~9号桶中（比如53,个位为3，则放入3号桶中）
(2)收集，再将放置在0~9号桶中的数据按顺序放到数组中
重复(1)(2)过程，从个位到最高位（比如32位无符号整形最大数4294967296，最高位10位）

2、算法分析:

平均时间复杂度：O(dn)(d即表示元素的最高位数,如果是int,则最大为32)
空间复杂度：O(10n) （10表示0~9，用于存储临时的序列）

稳定性：稳定
*/

#define BUCKET_NUM 10    //桶的数量，因为数字为0~9，故共10个
#define NUM_LEN 10      //元素的最大长度，即位数，32位unsigned int最大值42亿，共10位

int getPosNum(int val, int pos){    //取得元素val的第pos位的数字
    int base = 1;
    for(int i=1; i<pos; ++i){
        base *= 10;
    }
    return val/base%10;
}

void RadixSort(vector<int> &v){      //基数排序
    int len = v.size();
    if(len < 1)
        return;
    vector<vector<int> > radix_bucket(BUCKET_NUM, vector<int>(len+1, 0));       //一共10个桶,每个桶可放len+1个元素,其中第一个存放该桶元素个数

    for(int pos=1; pos<NUM_LEN; ++pos){     //从第一位开始
        for(int i=0; i<len; ++i){
            int bkt_index = getPosNum(v[i], pos);      //取出当前元素第i位的值
            int inner_index = ++radix_bucket[bkt_index][0];
            radix_bucket[bkt_index][inner_index] = v[i];    //放入桶中
        }
        for(int i=0, idx=0; i<BUCKET_NUM; ++i){     //每遍历完一个pos,就对原数组进行重排
            for(int j=1; j<=radix_bucket[i][0]; ++j){
                v[idx++] = radix_bucket[i][j];
            }
            radix_bucket[i][0] = 0;     //计数归零
        }
    }
}

int main(){
    int a = 345;
    vector<int> v;
    v.push_back(23);
    v.push_back(44);
    v.push_back(1270);
    v.push_back(56);
    v.push_back(63);
    v.push_back(87);
    v.push_back(909);
    v.push_back(41);
    v.push_back(5);
    v.push_back(238);
    RadixSort(v);
    for(int i=0; i<v.size(); ++i)
        cout<<v[i]<<",";
    return 0;
}
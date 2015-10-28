class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<2)
            return n;
        int k = 2, index = k;  //覆盖起始索引,扩展到最多允许k次重复，那么index=k
        for(int i=k; i<n; ++i){
            if(A[i]!=A[index-k]){   //如果k个以上相同，则index不变，否则替换index位置元素
                A[index++] = A[i];
            }
        }
        return index;
    }
};
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        //由小到大排序就是中序遍历的结果
        if(sequence.empty()) return false ;
        vector<int>mid = sequence ;
        //给后序遍历结果排序，从小到大，确定左右子树
        int res = getRes(sequence, 0, sequence.size()-1) ;
        return res ;
    }   
    int getRes(vector<int>seq, int start, int end) {
        if(start >= end) {
            return true ;
        }
        int root = seq[end] ;
        int index = start ;
        //找左子树的第一个节点
        while(seq[end] < root) {
            end-- ;
        }
        int j = index ;
        while(j<end) {
            if(seq[j] < root) {
                return false ;
            }
            j++ ;
        }
        return getRes(seq, start, index-1)&&getRes(seq, index, end-1) ;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}


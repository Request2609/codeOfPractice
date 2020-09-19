#include <iostream>
#include <vector>

class Solution {
public :
    bool VerifySquenceOfBst(std::vector<int>sequence) {
        if(sequence.empty()) {
            return false ;
        }
        int res = getRes(sequence, 0, sequence.size()-1) ;
        return res ;
    }

    int getRes(std::vector<int>seq, int left, int right) {
        if(left>=right) {
            return true ;
        }
        //获取到根节点，也就是后序遍历的最后一个元素
        int root = seq[right] ;
        int index = left ;
        //找左子树的第一个节点
        while(seq[right]>root) {
            right--;
        }
        //验证过左子树任意节点都小于根节点
        int j = index ;
        while(j<right) {
            if(seq[j]>root) {
                return false ;
            }
            j++ ;
        }
        return getRes(seq, left, index-1)&&getRes(seq, index, right-1) ;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}


#include <iostream>
#include <vector>
using namespace std ;
//在一个二维数组中，每一行都按照从左到右递增的顺序排序，
 //   每一列都按照从上到下递增的顺序排序。 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size() ;
        if(row == 0) return false;
        int col = array[0].size() ;   
        int r = 0 ;
        int c = col-1 ;     
        while(r<row&&c>=0) {
            int top= array[r][c] ;
            if(target == top) {
                return true ;
            }
            else if(target < top) --c ;
            else ++r ;
        }
        return false ;
    }
};

int main() {

    vector<vector<int>> ma{
            {1, 2, 8 , 9},
            {2, 4, 9, 12},
            {4, 7, 10, 13},
            {6, 8, 11, 15}
    };
    int tar ;
    cin >> tar ;
    Solution ss ;
    cout << ss.Find(tar, ma) << endl ;
    return 0;
}


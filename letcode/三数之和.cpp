#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>&tmp){
        std::vector<std::vector<int>>ls ;
        sort(tmp.begin(), tmp.end()) ;
        int left, right ;
        left = 0 ;
        right = tmp.size() ;
        std::vector<int>res ;
        //最左边的指针最右边的下标只可能到达right-2的位置
        for(int i=0; i<right-2; i++) {
            //当该元素大于0的时候，就跳出循环
            if(tmp[i]>0) {
                break ;
            }
            //跳过可能重复的答案
            if(i>0&&tmp[i]==tmp[i-1]) {
                continue ;
            }
            //设置左指针
            int l = i+1 ;
            //设置右指针
            int r = right-1 ;
            while(l<r) {
                //获取三个数的和
                int s = tmp[i]+tmp[l]+tmp[r] ;
                //要是和大于0，说明左边值太小，需要左移右指针
                if(s>0) --r ;
                //要是和小于0，说明右边值太大，需要将左指针右移
                else if(s<0) ++l ;
                //三数字之和等于0，放进容器中
                else ls.push_back({tmp[i], tmp[l], tmp[r]}) ;
                while(l<r) {
                    int s = l+1 ;
                    //左指针跳过重复值
                    if(tmp[s] != tmp[l]) {
                        break ;
                    }
                    l = s ;
                }
                //右指针跳过重复值
                while(l<r) {
                    int s = r-1 ;
                    if(tmp[s] != tmp[r]) {
                        break ;
                    }
                    r = s ;
                }
            }
        }
        return ls ;
    }
};

int main() {
    
    Solution ss ;
    std::vector<int>ls ;
    return 0;
}


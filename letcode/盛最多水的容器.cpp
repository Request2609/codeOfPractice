#include <iostream>
#include <vector>
#include <cmath>
//一开始，两个指针指向开头，一个指针指向结尾
//此时容器的低是最大的，接下来随着指针向内移动
//会造成容器的底变小，在这种情况下想要让容器
//水变多，就只有在容器的高上下功夫，我们在每次移动
//指针的时候，需要使高尽量大，所以我们选择指针所指向
//的高较小的那个指针进行移动，这样就保留了容器较高的那条边
//放弃了较小的那条边，尽量获得更高的边的机会
class Solution {
public :
    int maxArea(std::vector<int>&height) {
        int left = 0 ;
        int right = height.size()-1 ;
        int m = -1 ;
        int tmp = 0 ;
        while(1){
            tmp = height[left]>height[right]?height[right]:height[left]*abs(right-left) ;
            if(tmp > m) {
                m = tmp ;
            }
            if(left==right) break ;
            if(height[left]<height[right]) {
                left++ ;
            }
            else {
                right-- ;
            }
        }
        return m ;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}


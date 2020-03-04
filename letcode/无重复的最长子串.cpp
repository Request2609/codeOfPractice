#include <iostream>
#include <unordered_set>

class Solution {
public:
    //滑动窗口解决
    int lengthOfLongestSubstring(std::string s) {
        int left=0, right=0 ;
        int maxlen = INT32_MIN ;
        int slen = s.size() ;
        if(slen == 0 || slen == 1) return slen ;
        int index = 0 ;
        std::unordered_set<char> se ;
        while(right+1 < slen) {
            //那下一个，到前面的最长字符串，判断是否有重复
            for(index=left; index<=right; index++) {
                //有重复
                if(s[right+1] == s[index]) {
                    break ;
                }
            }
            //左边界移动到第一个重复字符之后的位置
            if(index<=right) {
                left = index+1 ;
            }
            //在原来串没找到重复，窗口扩大，
            right++ ; //窗口扩大
            maxlen = maxlen>(right-left+1)?maxlen:(right-left+1) ; 
        }       
        return maxlen ;
    }
};

int main() {

    Solution ss ;
    std::string s ;
    std::cin >> s ;
    std::cout << ss.lengthOfLongestSubstring(s) << std::endl ;
    return 0;
}


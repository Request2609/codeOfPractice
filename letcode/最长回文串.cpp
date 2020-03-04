#include <iostream>
using namespace std ;
//最长回文子串
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) {
            return "" ;
        }
        string result = "" ;
        for(int i=0; i<(int)s.length(); i++) {
            //从当前元素本身开始比较
            string lstr = getAround(s, i, i) ;
            //从当前元素和下一个元素的开始比较
            string rstr = getAround(s, i, i+1) ;
            string temp = lstr.size()>rstr.size()?lstr:rstr ;
            result = result.length()>=temp.length()?result:temp ;
        }
        return result ;
    } 

    string getAround(string s, int left, int right) {
        bool flag = false ;
        //left和right都移动
        while(left >=0 && right<(int)s.size() && s[left] == s[right]) {
                left-- ;
                right++ ;
                flag = true ;
        }

        if(flag) {
            //判断左右边界是否合法，左边界和右边界不相等
            if(left < 0 || right>(int)s.length()-1||s[left] != s[right]) {
                left+=1 ;
            }
        }   
        //返回相应的子串
        return s.substr(left, right-left) ;
    }
};
int main()
{
    Solution ss ;
    string sa;
    cin >> sa ;
    cout << ss.longestPalindrome(sa) << endl;
    return 0;
}


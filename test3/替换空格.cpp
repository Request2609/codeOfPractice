#include <iostream>
#include <vector>
#include <string.h>
using namespace std ;
//请实现一个函数，把字符串中的每个空格替换成 
//"%20"。 例如输入 "We are happy."，
//则输出"We%20are%20happy."。
class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(length < 0) return ;
        int index = 0 ;
        int count =0 ;
        int len = strlen(str) ;
        while(index < len) {
            if(str[index] == ' ') {
                count++ ;
            }   
        }
        int nl = count*2+len ;
        if(len > length) {
            return ;
        }
        str[len] = '\0' ;
        int point = len-1 ;
        int point1 = nl-1 ;
        while(point>=0&&point1>point){
            if(str[point] == ' ') {
                str[point1--] = '0' ;
                str[point1--] = '2' ;
                str[point1--] = '%' ;
            }
            else {
                str[point1--] = str[point] ;
            }
            point--;
        }
    }   
};
int main() {
    
    return 0;
}


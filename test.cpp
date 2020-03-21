#include <iostream>
#include <vector>
//评测题目: c++ , 给定一个数组和一个数组下标，请根据下标值把数组“对折”一下。
// 如 给定数组： 1，2，3，4，5，6，7，8，9 和下标3. 结果为：7，6，5，4，3，2，1，8，9
// 注意考虑边界条件
void swap(int&num1, int& num2) {
	int tmp = std::move(num1) ;
  	num1 = std::move(num2) ;
  	num2 = std::move(tmp) ;
}

void fun( std::vector<int>& array , int index){
	int len = array.size();
  	if(len-1<index) {
    	return ;
    }
  	int left = index-1;
  	int right = index+1;
  	while(left>=0&&right<len) {
    	swap(array[left], array[right]);
      	left--;
      	right++ ;
    }
  	if(left<0) {
    	return;
    }
 	std::vector<int> tmp ;
  	index = left ;
  	for(int i=left+1; i<len; i++) {
    	tmp.push_back(array[i]) ;
    }
  	for(int i=0; i<=index; i++) {
    	tmp.push_back(array[i]) ;
    }
  	array = tmp ;
}
int main()
{
    std::vector<int>ls ;
    while(1) {
        int a ;
        std::cin >>a ;
        if(a == -1) break ;
        ls.push_back(a) ;
    }
    int index ; 
    std::cin >> index ;
    fun(ls, index) ;
    for(int i=0; i<(int)ls.size(); i++) {
        std::cout << ls[i] << " " ;
    }
    std::cout << std::endl ;
    return 0;
}

#include <iostream>
#include <map>
#include "links.h"

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==NULL||pHead2==NULL) {
            return NULL ; 		
        }
        std::map<ListNode*, int>ls ;
        auto cur = pHead1 ;       
        auto cur1 = pHead2 ;
        while(cur) {
            ls.insert({cur,1}) ;
            cur = cur->next ;
        }
        int flag = 0 ;
        while(cur1) {
            if(ls.find(cur1) == ls.end()) {
                cur1 = cur1->next ;
            }
            else {
                flag = 1 ;
                break ;
            }
        }
        if(flag == 0) return NULL ;
        return cur1 ;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}


#include <iostream>

#include <vector>
#include "links.h"
using namespace std ;
class Solution {
public:
    ListNode* ReverseList(ListNode* head) {
        vector<int>ls ;
        ListNode* cur = head ;   
        if(cur == NULL) {
            return NULL ;
        }
        ListNode* nexts = cur->next ;
        ListNode* tmp = nexts ;
        int flag = 0 ;
        while(nexts) {
            flag = 1 ;
            tmp = nexts->next ;
            nexts->next = cur ;
            if(cur == head) {
                cur->next = NULL ;
            }
            cur = nexts ;   
            nexts = tmp ;
        }
        if(flag == 0) {
            return head ;
        }
        return cur ;
    }
};


int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}


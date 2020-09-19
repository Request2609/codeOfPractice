#include <iostream>

#include <vector>
#include "links.h"
using namespace std ;
//输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int>ls ;
        ListNode* cur = head ;   
        if(cur == NULL) {
            return ls ;
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
            ls.push_back(tmp->val) ;
            ls.push_back(nexts->val) ;
            return ls ;
        }
        head = cur ;
        tmp = head ;
        while(tmp) {
            ls.push_back(tmp->val) ;
            tmp = tmp->next ;
        }
        return ls ;
    }
};

int main() {
    ListNode* head= NULL ;
    create(&head) ;
    Solution ss ;
    ss.printListFromTailToHead(head) ;
    destroy(head) ;
    return 0;
}


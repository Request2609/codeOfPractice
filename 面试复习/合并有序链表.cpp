#include <iostream>
using namespace std ;
//合并链表
struct ListNode {
    struct ListNode* next ;
    int val;
};
//合并两个链表
class Solution {
    ListNode* mergeTwoLists(ListNode*l1, ListNode*l2) { 
        if(l1 == NULL){
            return l2 ;
        }
        if(l2 == NULL) {
            return l1 ;
        }
        if(l1->val<l2->val) {
            l1->next = mergeTwoLists(l1->next, l2) ;
            return l1 ;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next) ;
            return l2 ;
        }
    }
};



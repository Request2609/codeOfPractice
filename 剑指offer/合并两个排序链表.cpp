#include <iostream>
#include "links.h"
using namespace std ;
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL) return pHead2 ;
        if(pHead2 == NULL) return pHead1 ;
        ListNode* cur1 = pHead1 ;          
        ListNode* cur2 = pHead2 ;          
        ListNode* pre = cur1 ;
        ListNode* next2 = cur2->next ;
        while(cur1&&next2) {
            if(cur1->val >= cur2->val) {
                if(cur1==pHead1) {
                    pHead2->next = pHead1 ;
                    pHead1 = pHead2 ;
                    pre = pHead1 ;
                    cur2 = next2 ;
                    next2 = next2->next ;
                }
                else {
                    cur2->next = cur1 ;
                    pre->next = cur2 ;
                    pre = cur2 ;
                    cur1 = pre->next ;
                    cur2 = next2 ;
                    next2 = next2->next ;
                }
            }
            else {
                pre = cur1 ;
                cur1 = cur1->next ;
            }
        }
        if(cur1)
            cur1->next = cur2 ;
        else 
            pre->next = cur2 ;
        return pHead1 ;
    }
};
int main() {
    ListNode* head1 = NULL ;
    ListNode* head2 = NULL ;
    create(&head1) ;
    create(&head2) ;
    Solution ss ;
    ss.Merge(head1, head2) ;
    print(head1) ;
    destroy(head1) ;
    return 0;
}


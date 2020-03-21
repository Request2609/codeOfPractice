#include <iostream>
#include "links.h"

class Solution {
public :
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* newHead = new ListNode(0) ;
        ListNode* ptr = newHead ;
        while(head1&&head2) {
            if(head1->val > head2->val) {
                newHead->next = head2 ;
                head2 = head2->next ;
            }
            else {
                newHead->next = head1 ;
                head1 = head1->next ;
            }
            newHead  = newHead->next ;
        }
        if(head1 != nullptr) {
            newHead->next = head1 ;
        }
        if(head2 != nullptr) {
            newHead->next = head2 ;
        }
        return ptr->next ;
    }

    ListNode*Merge(ListNode* head1, ListNode* head2) {
        ListNode newHead(0) ;
        ListNode* pi = &newHead ;
        while(head1&&head2) {
            if(head1->val>head2->val) {
                //将两个节点交换，然后再使用pi指向小节点
                if(head1->val>head2->val) swap(head1, head2) ;
                pi->next = head1 ;
                head1 = head1->next ;
                pi = pi->next ;
            }
        }
        pi->next = head1?head1:head2 ;
        return pi ;
    }

    void swap(ListNode* &head1, ListNode* &head2) {
        auto tmp = std::move(head1) ;
        head1 = std::move(head2) ;
        head2 = std::move(tmp) ;
    }
};

int main() {
    ListNode* head, *head1 ;
    create(&head) ;
    print(head) ;
    create(&head1) ;
    print(head1) ;
    Solution ss ;
    ss.Merge(head, head1) ;
    print(head1) ;
    destroy(head) ;
    destroy(head) ;
    return 0;
}


#include <iostream>
#include "links.h"


ListNode* merge(ListNode* head1, ListNode* head2) {
    if(head1 == NULL) {
        return head2 ;
    }
    if (head2 == NULL) {
        return head1 ;
    }
    ListNode* head = NULL ;
    if (head1->val > head2->val) {
        head = head2 ;
        head->next = merge(head1, head2->next) ;
    }
    else {
        head = head1 ;
        head->next = merge(head1->next, head2) ;
    }
    return head ;
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}


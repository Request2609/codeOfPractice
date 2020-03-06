#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //先逆置链表，然后遍历
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head ;
        ListNode* low = head ; 
        ListNode* fast = head ;
        int count = 0 ;
        int index = 0 ;
        while(fast) {
            if(n>count) {
                low = low->next ;
                if(fast!=NULL&&fast->next!=NULL) {
                    count+=2 ;
                    fast = fast->next->next ;
                }
            }
            else {
                int num = count-n ;
                index = count/2+(count/2-num-1) ;
                break ;
            }
        }
        while(index--) {
            low = low->next ;
        }
        low->next = low->next->next ;
        return head ;
    }
    //解决方法
    ListNode* removeNthFromEnd1(ListNode*head, int n) {
        if(!head||!head->next) return NULL ;
        ListNode* fast = head,*slow = head ;
        for(int i=0; i<n&&fast; i++) {
            fast = fast->next ;
        }
        if(!fast) {
            return head->next ;
        }
        while(fast->next) {
            fast = fast->next ;
            slow = slow->next ;
        }
        slow->next = slow->next->next ;
        return head ;
    }

};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}


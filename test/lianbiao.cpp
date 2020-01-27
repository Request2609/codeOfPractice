#include <iostream>
using namespace std ;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return  ;
        }
        ListNode * cur = head->next  ;
        ListNode* tmp = head->next ;
        ListNode* n = cur->next ;
        while(n) {
            cur = n ;
            tmp->next = cur->next ;
            n = n->next ;
            cur->next = head->next ;
            head->next = cur ;
            tmp = tmp->next ;
        }          
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}


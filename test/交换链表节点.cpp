#include <iostream>
#include "links.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) {
            return NULL ;
        }       
        ListNode * tmp = head ;
        ListNode* cur = head->next ;
        while(cur) {
            swap(cur, tmp) ;

            tmp = cur->next ;
            if(tmp != NULL) {
                cur = tmp->next ;
            }
            else {
                break;
            }
        }
        return head ;
    }
    void swap(ListNode* tmp, ListNode* tmp1) {
        int s = move(tmp->val) ;
        tmp->val =  move(tmp1->val) ;
        tmp1->val = move(s) ;
    }
};
int main() {
    ListNode* cur = NULL ;   
    create(&cur) ;
    print(cur) ;
    Solution ss ;
    ss.swapPairs(cur) ;
    print(cur) ;
    destroy(cur) ;
}

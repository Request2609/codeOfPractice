#include<iostream>
#include <map>
using namespace std ;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, bool> mp ;
        auto cur1 = headA ;
        auto cur2 = headB ;
        while(cur1) {
            mp[cur1] = true ;
            cur1 = cur1->next ;
        }
        while(cur2) {
            if(mp[cur2]) {
                return cur2 ;
            }
            cur2 = cur2->next ;
        }
        return NULL ;
    }
};


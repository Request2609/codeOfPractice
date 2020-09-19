#include <iostream>
#include <vector>
#include "links.h"
using namespace std ;

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        vector<ListNode*> ls ;
        if(pListHead == NULL) return NULL ;
        while(1) {
            ListNode* cur = pListHead  ;      
            ls.push_back((cur)) ;
            pListHead = pListHead->next ;
            if(pListHead == NULL) {
                break ;
            }
        }
        int len = ls.size() ;
        int index =len-k ;
        return ls[index] ;
    }
    //正解
    ListNode* FindKthToTail3(ListNode* pListHead, unsigned int k) {
        if(pListHead == nullptr || k == 0)
            return nullptr;

        ListNode* pAhead = pListHead;
        ListNode* pBehind = nullptr;

        for(unsigned int i=0; i<k-1; i++){
            if(pAhead->next != nullptr)
                pAhead = pAhead->next;
            else
                return nullptr;
        }
        pBehind = pListHead;
        while(pAhead->next != nullptr){
            pAhead = pAhead->next;
            pBehind = pBehind->next;
        }
        return pBehind;
    }
    //逆置链表的思路，再找出想要找的节点
    ListNode* FindKthToTail1(ListNode* pl, unsigned int k) {
        ListNode* cur = pl ;   
        ListNode* nexts = cur->next ;
        ListNode* tmp = nexts ;
        int flag = 0 ;
        while(nexts) {
            flag = 1 ;
            tmp = nexts->next ;
            nexts->next = cur ;
            if(cur == pl) {
                cur->next = NULL ;
            }
            cur = nexts ;   
            nexts = tmp ;
        }
        pl = cur ;       
        while(pl) {
            k-- ;
            if(k == 0) break ;
            pl = pl->next ;
        }
        return pl ;
    }
};

int main()
{
    ListNode* head= NULL ;
    create(&head) ;
    Solution ss ;
    int a ;
    cin >> a ;
    ListNode* cur= ss.FindKthToTail1(head, a) ;
    cout << cur->val << endl ;
    destroy(head) ;
    return 0;
}


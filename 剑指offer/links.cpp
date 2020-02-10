#include "links.h"
 
void create(ListNode** head) {
    *head = NULL ;
    *head = (ListNode*)malloc(sizeof(ListNode)) ;
    (*head)->next= NULL ;
    int flag = 0 ;
    ListNode* cur = *head ;
    while(1) {
        ListNode* ne =NULL;
        int a ;
        cin >> a ;
        if(a == -1) break ;
        if(flag == 0) {
            (*head)->val = a ;
            flag = 1 ;
            continue ;
        }   
        ne =(ListNode*)malloc(sizeof(ListNode)) ;
        ne->val = a ;
        ne->next = cur->next;
        cur->next = ne ;
        cur = ne ;   
    }
}

void print(ListNode* head){
    ListNode* cur = head  ;
    while(cur) {
        cout << cur->val<< "  " ;
        cur = cur->next ;
    }
    cout << endl ;
}
void destroy(ListNode* head) {
    ListNode* cur = head->next ;
    while(cur) {
        head->next = cur->next ;
        free(cur) ;
        cur = head->next ;
    }
    free(head) ;
}

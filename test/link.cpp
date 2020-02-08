#include <iostream>

using namespace std ;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
void create(ListNode** head) {
    *head = NULL ;
    *head = (ListNode*)malloc(sizeof(ListNode)) ;
    (*head)->next= NULL ;
    while(1) {
        ListNode* ne =NULL;
        int a ;
        cin >> a ;
        if(a == -1) break ;
        ne =(ListNode*)malloc(sizeof(ListNode)) ;
        ne->val = a ;
        ne->next = (*head)->next ;
        (*head)->next = ne ;
    }
}

void print(ListNode* head){
    ListNode* cur = head->next  ;
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
/*
<div class="notranslate"><p>删除链表中等于给定值&nbsp;<strong><em>val&nbsp;</em></strong>的所有节点。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 1-&gt;2-&gt;6-&gt;3-&gt;4-&gt;5-&gt;6, <em><strong>val</strong></em> = 6
<strong>输出:</strong> 1-&gt;2-&gt;3-&gt;4-&gt;5
</pre>
</div>
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) {
            return head ;
        }
        ListNode* cur = head ;
        ListNode* pre = head ;
        while(cur) {
            if(cur == head && cur->val == val) {
                head = cur->next ;
                pre = head ;
                cur = cur->next ;
                continue ;
            }
            if(cur->val == val) {
                pre->next = cur->next ;
                cur = pre->next ;
            }
            else {
                pre = cur ;
                cur = cur->next ;
            }
        }   
        return head ;
    }
};


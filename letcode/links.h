#pragma once

#include <iostream>

using namespace std ;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

void create(ListNode** head) ;

void destroy(ListNode* head) ;

void print(ListNode* head);

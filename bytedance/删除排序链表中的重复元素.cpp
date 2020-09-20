#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public :
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head ;
        }
        int flag = 0 ;
        auto prev = head ;
        auto cur = head->next ;
        while(cur) {
            if (cur->val == prev->val) {
                cur = cur->next ;
                flag = 1 ;
            }else {
                if (flag == 1) {
                    if (prev == head) {
                        head = prev ;
                    }
                    else {
                        prev->next = cur ;
                    }
                } 
                flag = 0 ;
                prev = cur ;
                cur = cur->next ;
            }
        }
        return head ;
    }
};

int main() {
    std::cout << "Hello world" << std::endl;
    return 0;
}


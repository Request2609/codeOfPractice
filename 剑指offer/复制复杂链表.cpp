#include <iostream>
#include <map>
using namespace std ;
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution1 {
public:
    //将新建的节点加到链表中
    //新旧节点交替
    //最后找random互相赋值
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL) return NULL ;
        RandomListNode* cur = pHead ;
        RandomListNode* copy = NULL ;
        while(cur) {
            copy = (RandomListNode*)malloc(sizeof(RandomListNode)) ;
            copy->label = cur->label ;
            copy->next = cur->next ;
            cur->next = copy ;
            cur = copy->next ;
        }
        cur = pHead ;
        while(cur) {
            copy = cur->next ;
            copy->random = cur->random==NULL?NULL:cur->random->next ;
            cur = cur->next->next ;
        }
        cur = pHead ;
        pHead = cur->next ;
        while(1) {
            copy = cur->next ;
            cur->next = copy->next ;
            if(cur == NULL) break ;
            else copy->next = cur->next ;
        }
        return pHead ;
    }   

};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}


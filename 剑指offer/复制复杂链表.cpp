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

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode* head = NULL ;
        RandomListNode* cur = pHead ;          
        if(cur == NULL) { return head ; }
        //建立映射关系
        map<int, int>mp1 ;
        map<int, RandomListNode*>mp2 ;
        RandomListNode* tmp = NULL ;
        RandomListNode* nexts = NULL ;
        int index = 0 ;
        //建立一套映射
        while(cur) {
            if(cur->random) {
                int i = 0 ;
                RandomListNode* ss = head ;
                while(ss != cur->random) {
                    i++ ;
                    ss = ss->next ;
                }
                mp1[index] = i ;
            }       
            cur = cur->next ;      
        }
        cur = pHead ;
        index = 0 ;
        //先遍历第一个链表，将含有关系的节点编号存入map
        while(cur) {
            if(cur == pHead) {
                head = (RandomListNode*)malloc(sizeof(RandomListNode)) ;
                head->label = pHead->label ;
                head->next = NULL ;
                head->random = NULL ;
                tmp = head ;
            }
            else {
                nexts =(RandomListNode*)malloc(sizeof(RandomListNode)) ;
                nexts->label = cur->label ;
                nexts->next = tmp->next ;   
                tmp->next = nexts ;
                tmp = nexts ;
                //建立映射 id-->新节点
                mp2[index] = nexts ; 
                nexts = tmp->next ;
            }
            index++ ;
            cur = cur->next ;
        }
        //设置random值
        for(auto res= mp2.begin(); res != mp2.end(); res++) {
            if(mp1.find(res->first) != mp1.end()) {
                res->second->random = mp2[res->first] ;
            }
        }
        return head ;
    }       
};

class Solution1 {
public:
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


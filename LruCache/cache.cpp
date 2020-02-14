#include "cache.h"

int cache::insert(shared_ptr<node>data) {
    if(count == 0) {
        head = data ;
        head->nexts = nullptr ;
        head->pre = nullptr ;
        tail = head ;
    }
    //当前缓存还够用，将节点插入到链表尾部
    if(count < num) {
        tail->nexts = data ;
        data->pre = tail ;
        tail = data ;
        count++ ;
    }
    if(count >=num){
        head = head->nexts ;   
        tail->nexts = data ;
        data->pre = tail ;
        tail = data ;
    }
    return 1 ;   
}

bool cache::accessData(int num) {
    shared_ptr<node>cur = head ;
    while(cur) {
        if(cur->val == num) {
            moveLast(cur) ;
            return true ;
        }
        cur = cur->nexts;
    }
    return 1;
}

//将被访问的节点挪到链表尾部
void cache::moveLast(shared_ptr<node>cur) {
    cur->pre->nexts = cur->nexts ;  
    cur->nexts->pre = cur->pre ;
    tail->nexts = cur ;
    cur->pre = tail ;
}



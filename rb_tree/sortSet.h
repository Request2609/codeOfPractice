#pragma once
#include <iostream>
#include <memory>
#include <queue>
#include "rb_tree.h"
using namespace std ;

class dbObject {
public:
    dbObject() {}
    virtual ~dbObject() {}
public :
    virtual void print() = 0;
    //set操作
    virtual long long  getEndTime() = 0 ;
    virtual void setEndTime(long long e) = 0 ;
    virtual int getType() = 0 ;
    virtual void setType(int type) = 0;
    virtual void setKey(string k) = 0;
    virtual void setValue(string v, ...) = 0;
    virtual void setName(string name) = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                
    virtual void setNum(int num) = 0;
    virtual string  getName() = 0;
    virtual string getKey() = 0;
    virtual int getNum() = 0 ;
    virtual string getValue() = 0;
    virtual vector<string> getValues(const string s) = 0;
    virtual int objectSize() = 0 ;
    //获取命令编号
};


//set对象
class sortSet : public dbObject {
public :
    sortSet() {
        timeout = -1 ;
    }
    ~sortSet() {}
public :
    vector<string> getValues(const string s) {}
    void print() ;
    long long getEndTime() { return timeout ; }
    void setEndTime(long long e) {this->timeout = e ;}
    int getType() { return type ; }
    void setType(int type) { this->type = type ; }
    void setKey(string k) { this->key = k ; }
    void setValue(string value, ...)  { this->value =  value ; }
    void setName(string name) { this->name = name ; }
    void setNum(int num) { this->num = num ; }
    string  getName() { return name ; }
    string getKey() { return key ; }
    int getNum() { return num ; }
    string getValue() { return value ; }
    int objectSize() { return 1 ;}
public :
    shared_ptr<rb_tree>rbt ;
    //类型
    int type ;
    //命令名称
    string name ;
    long long timeout ;
    //当前设置的超时时间
    //所在数据库编号
    int num ;
    //命令键值
    string key ;
    string value ;
} ;


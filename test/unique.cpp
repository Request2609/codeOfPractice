#include <iostream>
#include <memory>
using namespace std ;
class B;
class A
{
public:
    shared_ptr<B> pb_;
    ~A()
    {
        cout<<"A delete\n";
    }
    void print() {
        cout << "hello world!" << endl ;
    }
};
class B
{
public:
    weak_ptr<A> pa_;
    ~B()
    {
        cout<<"B delete\n";
    }
};
void fun()
{
    shared_ptr<B> pb(new B());
    shared_ptr<A> pa(new A());
    pb->pa_ = pa;
    shared_ptr<A>aa = pb->pa_.lock() ;
    aa->print() ;
    pa->pb_ = pb;
    cout<<pb.use_count()<<endl;
    cout<<pa.use_count()<<endl;
}
int main()
{
    fun();
    return 0;
}

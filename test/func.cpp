#include <iostream>
using namespace std;
 
class A {
public:
	virtual void vfunc1() { cout << "A::vfunc1()" << endl; };
	virtual void vfunc2() { cout << "A::vfunc2()" << endl; };
	void func1() { cout << "A::func1()" << endl; };
	void func2() { cout << "A::func2()" << endl; };
private:
	int data1_;
	int data2_;
};
 
class B :public A {
public:
	virtual void vfunc1() override { cout << "B::vfunc1()" << endl; };
	void func2() { cout << "B::func2()" << endl; };
private:
	int data3_;
};
 
class C :public B {
public:
	virtual void vfunc1() override { cout << "C::vfunc1()" << endl; };
	void func2() { cout << "C::func2()" << endl; };
private:
	int data1_, data4_;
};
 
//演示了手动调用虚函数的过程
int main() {
	B a;
	typedef void(*Fun)(void);
	Fun pFun = nullptr;
	cout << "虚函数表地址：" << (int*)(&a) << endl;
	cout << "虚函数表第1个函数地址："<<(int*)*(int*)(&a) << endl;
	cout << "虚函数表第2个函数地址：" << (int*)*(int*)(&a) + 1 << endl;
	pFun = (Fun)*((int*)*(int*)(&a));
	pFun();
	pFun = (Fun)*((int*)*(int*)(&a) + 1);
	pFun();
	return 0;
}

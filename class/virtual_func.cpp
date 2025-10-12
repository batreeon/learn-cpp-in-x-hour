#include <iostream>

class Base {
public:
    virtual ~Base() {
        std::cout << "Base::~Base()" << std::endl;
    }
};

class Derived: public Base {
public:
    ~Derived() override {
        std::cout << "Derived::~Derived()" << std::endl;
    }
};

// 析构函数建议是虚函数：
// 当通过基类指针删除派生类对象时，如果析构函数不是虚函数，只会调用基类的析构函数，导致派生类资源泄漏
int main() {
    Base *p = new Derived;
    delete p;
}
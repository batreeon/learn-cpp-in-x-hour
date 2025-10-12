虚函数：

[virtual_func](./class/virtual_func.cpp)

基类的析构函数应该为虚函数，否则当使用基类的指针或引用销毁对象时，只会调用基类的析构函数，可能造成资源泄漏。
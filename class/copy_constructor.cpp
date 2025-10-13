#include <iostream>
#include <fstream>

class Vector {
private:
    double *elem;
    int sz;
public:
    // 构造函数和析构函数
    Vector(int s): elem{new double[s]}, sz{s} {}
    Vector(std::initializer_list<double>);
    ~Vector() { delete[] elem; }

    // 拷贝构造函数
    Vector(const Vector& v);
    // 拷贝赋值运算符
    Vector& operator=(const Vector& v);

    double& operator[](int i){ return elem[i]; }
    const double& operator[](int i) const {return elem[i]; }

    friend std::ostream& operator<<(std::ostream& os, const Vector& v);

    int size() const {
        return sz;
    }
};

Vector::Vector(std::initializer_list<double> lst): elem{new double[lst.size()]}, sz{lst.size()} {
    std::copy(lst.begin(), lst.end(), elem);
}

Vector::Vector(const Vector& v): elem{new double[v.sz]}, sz{v.sz}{
    for (int i = 0; i < v.sz; ++i) {
        elem[i] = v.elem[i];
    }
}

Vector& Vector::operator=(const Vector& v) {
    delete[] elem;
    double *elem = new double[v.sz];
    for (int i = 0; i < v.sz; ++i) {
        elem[i] = v[i];
    }
    sz = v.sz;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& v){
    for (int i = 0; i < v.size(); ++i) {
        os << v.elem[i] << " ";
    }
    os << std::endl;
    return os;
}

int main() {
    Vector v1 = Vector({1,0,0,0});
    Vector v2 = v1;
    Vector v3(v2);
    v1[0] = 2;
    v2[1] = 3;
    v3[2] = 4;
    std::cout << v1;
    std::cout << v2;
    std::cout << v3;
}

#include <iostream>

class Vector {
private:
    double *elem;
    int sz;
public:
    // 构造函数和析构函数
    Vector(int s): elem{new double[s]}, sz{s} {}
    Vector(std::initializer_list<double>);
    ~Vector() { delete[] elem; }

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
    // 默认的拷贝操作会造成报错，因为会导致对一个资源的重复释放
    std::cout << v1;
    std::cout << v2;
    std::cout << v3;
}

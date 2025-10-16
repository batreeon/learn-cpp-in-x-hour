#include <thread>
#include <future>
#include <numeric>
#include <vector>
#include <iostream>

double accum(double* beg, double* end, double init){
    return std::accumulate(beg, end, init);
}

double comp2(std::vector<double>& v){
    using Task_type = double(double*, double*, double);

    // pakcaged_task负责将函数的返回值或异常放入一个promise中
    std::packaged_task<Task_type> pt0 {accum};
    std::packaged_task<Task_type> pt1 {accum};

    std::future<double> f0 {pt0.get_future()};
    std::future<double> f1 {pt1.get_future()};

    double* first = &v[0];
    // packaged_task不能被拷贝
    std::thread t1 {std::move(pt0), first, first + v.size()/2, 0};
    std::thread t2 {std::move(pt1), first + v.size()/2, first + v.size(), 0};

    t1.join();
    t2.join();

    double s0 {f0.get()};
    double s1 {f1.get()};
    std::cout << "s0: " << s0 << ", s1: " << s1 << "\n";

    return s0 + s1;
}

int main() {
    const size_t length = 10;
    std::vector<double> v(length);
    for(size_t i = 0; i < length; ++i) v[i] = i;

    double res = comp2(v);
    return 0;
}
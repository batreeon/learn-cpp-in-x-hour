#include <iostream>
#include <future>
#include <numeric>
#include <vector>

double accum(double* beg, double* end, double init){
    return std::accumulate(beg, end, init);
}

double comp4(std::vector<double>& v){
    auto f0 = std::async(accum, &v[0], &v[v.size()/2], 0);
    auto f1 = std::async(accum, &v[v.size()/2], &v[v.size()], 0);

    double s0 {f0.get()};
    double s1 {f1.get()};
    std::cout << "s0: " << s0 << ", s1: " << s1 << "\n";

    return s0 + s1;
}

int main() {
    const size_t length = 10;
    std::vector<double> v(length);
    for(size_t i = 0; i < length; ++i) v[i] = i;

    double res = comp4(v);
    return 0;
}
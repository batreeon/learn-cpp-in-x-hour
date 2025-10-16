#include <future>
#include <iostream>


void f(std::promise<int>& p) {
    try {
        p.set_value(42);
    } catch (...) {
        p.set_exception(std::current_exception());
    }
}

void g(std::future<int>& f) {
    try {
        int x = f.get();
        std::cout << "value: " << x << "\n";
    } catch (...) {
        std::cout << "exception caught\n";
    }
}

int main() {
    std::promise<int> p;
    std::future<int> fut = p.get_future();

    std::thread t1(g, std::ref(fut));
    std::thread t2(f, std::ref(p));

    t1.join();
    t2.join();

    return 0;
}
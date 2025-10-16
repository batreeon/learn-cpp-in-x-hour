#include <thread>
#include <iostream>

void do_work() {
    // sleep 2 seconds
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    do_work();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - start;

    // 输出耗时
    std::cout << "Elapsed time: ";
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() << " milliseconds\n";
    return 0;
}
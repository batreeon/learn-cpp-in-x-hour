#include <iostream>
#include <queue>

int main()
{
    // 默认使用 deque 作为底层容器
    std::queue<int> q1;
    std::queue<int> q2(std::deque<int>{1, 2, 3}); // 用 deque 初始化

    q1.push(1);
    q1.push(2);
    q1.push(3);

    std::cout << q1.size() << std::endl; // 3
    std::cout << q1.front() << std::endl; // 1
    std::cout << q1.back() << std::endl;  // 3

    q1.pop(); // 弹出 1
    std::cout << q1.front() << std::endl; // 2

    q1.pop(); // 弹出 2
    q1.pop(); // 弹出 3

    std::cout << q1.empty() << std::endl; // 1

    // size, empty
    // push, pop, front, back

    return 0;
}
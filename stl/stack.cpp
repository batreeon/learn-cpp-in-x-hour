#include <iostream>
#include <stack>

int main()
{
    // 默认使用 deque 作为底层容器
    std::stack<int> st1;
    std::stack<int> st2(std::deque<int>{1, 2, 3}); // 用 deque 初始化

    st1.push(1);
    st1.push(2);
    st1.push(3);

    std::cout << st1.size() << std::endl; // 3
    std::cout << st1.top() << std::endl;  // 3

    st1.pop(); // 弹出 3
    std::cout << st1.top() << std::endl;  // 2

    st1.pop(); // 弹出 2
    st1.pop(); // 弹出 1

    std::cout << st1.empty() << std::endl; // 1

    // size, empty
    // push, pop, top

    return 0;
}
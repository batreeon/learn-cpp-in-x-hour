#include <iostream>
#include <queue> // std::priority_queue
#include <vector>
#include <functional> // std::greater

int main()
{
    // 默认最大堆 (值最大的元素在 top)
    std::priority_queue<int> pq1;
    // 使用 vector 作为底层容器，std::less 作为比较器 (默认)
    std::priority_queue<int, std::vector<int>, std::less<int>> pq2;

    // 创建最小堆 (值最小的元素在 top)，使用 greater 比较器
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq3;

    pq1.push(3);
    pq1.push(1);
    pq1.push(4);
    pq1.push(1);
    pq1.push(5);

    std::cout << pq1.size() << std::endl; // 5
    std::cout << pq1.top() << std::endl;  // 5 (最大值)

    pq1.pop(); // 弹出 5
    std::cout << pq1.top() << std::endl;  // 4

    pq3.push(3);
    pq3.push(1);
    pq3.push(4);
    pq3.push(1);
    pq3.push(5);

    std::cout << pq3.top() << std::endl;  // 1 (最小值)

    std::cout << pq1.empty() << std::endl; // 0

    // size, empty, top
    // push, pop

    return 0;
}
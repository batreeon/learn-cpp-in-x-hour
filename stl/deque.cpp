#include <iostream>
#include <deque>

int main()
{
    std::deque<int> dq1;
    std::deque<int> dq2(2, 5); // 2个元素，每个元素值为5
    std::deque<int> dq3 = {1, 2, 3, 4, 5};

    std::cout << dq3[0] << " " << dq3.at(1) << " " << dq3.size() << std::endl; // 1 2 5

    std::cout << dq3.front() << " " << dq3.back() << " " << dq3.size() << std::endl; // 1 5 5

    dq3.push_back(6);
    dq3.push_front(0);
    dq3.insert(dq3.begin() + 2, 10); // 在索引2的位置插入10

    // 0 1 10 2 3 4 5 6
    for (const auto& val : dq3)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 0 1 10 2 3 4 5 6
    for (auto it = dq3.begin(); it != dq3.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    dq3.pop_back();
    dq3.pop_front();
    dq3.erase(dq3.begin() + 1); // 删除索引1处的元素 (即原来的10)

    // 1 2 3 4 5
    for (const auto& val : dq3)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << dq3.empty() << std::endl; // 0

    // 拷贝一个 deque
    std::deque<int> dq4 = dq3;
    std::deque<int> dq5(dq3);

    // size, max_size, empty, clear
    // operator[], at, front, back
    // push_front, push_back, pop_front, pop_back
    // insert, erase, emplace_front, emplace_back, emplace
    // swap, assign

    return 0;
}
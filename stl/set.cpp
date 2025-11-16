#include <iostream>
#include <set>
#include <algorithm> // std::find

int main()
{
    std::set<int> s1; // 空集合
    std::set<int> s2 = {3, 1, 4, 1, 5, 9}; // 初始化列表 (重复元素会被忽略)
    // s2 实际内容为 {1, 3, 4, 5, 9}

    std::cout << s2.size() << std::endl; // 5

    // 插入元素 (自动排序且不重复)
    s1.insert(10);
    s1.insert(5);
    s1.insert(15);
    // s1 内容: {5, 10, 15}

    // 查找元素
    auto it = s2.find(4);
    if (it != s2.end()) {
        std::cout << "Found: " << *it << std::endl; // Found: 4
    }

    // 使用 count 检查元素是否存在 (存在返回1，不存在返回0)
    std::cout << s2.count(10) << std::endl; // 0
    std::cout << s2.count(1) << std::endl;  // 1

    // 遍历 (自动有序)
    for (const auto& val : s1) {
        std::cout << val << " "; // 5 10 15
    }
    std::cout << std::endl;

    // 删除元素
    s1.erase(10); // 删除值为10的元素
    // s1 内容: {5, 15}

    // lower_bound, upper_bound 用于范围查找
    auto lower = s2.lower_bound(4); // 指向 >= 4 的第一个元素 (即4本身)
    auto upper = s2.upper_bound(4); // 指向 > 4 的第一个元素 (即5)
    std::cout << "Range for 4: [" << *lower << ", " << *upper << ")" << std::endl; // Range for 4: [4, 5)

    for (const auto& val : s1) {
        std::cout << val << " "; // 5 15
    }
    std::cout << std::endl;

    std::cout << s1.empty() << std::endl; // 0

    // size, max_size, empty, clear
    // insert, erase
    // find, count, lower_bound, upper_bound, equal_range
    // swap, emplace, emplace_hint

    return 0;
}
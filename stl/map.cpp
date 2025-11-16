#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<int, std::string> m1; // 空映射
    // map 是键值对 (key-value pair) 的集合，按键排序，键唯一
    std::map<int, std::string> m2 = {
        {1, "one"},
        {3, "three"},
        {2, "two"}
        // {3, "three again"} // 重复的键会被忽略
    };
    // m2 内容: { {1, "one"}, {2, "two"}, {3, "three"} }

    std::cout << m2.size() << std::endl; // 3

    // 插入/访问元素 (operator[] 如果键不存在会创建一个默认值)
    m1[10] = "ten";
    m1[20] = "twenty";
    // m1 内容: { {10, "ten"}, {20, "twenty"} }

    // 使用 insert 插入
    m1.insert(std::make_pair(15, "fifteen"));
    // 或者使用花括号列表 (C++11)
    m1.insert({5, "five"});
    // m1 内容: { {5, "five"}, {10, "ten"}, {15, "fifteen"}, {20, "twenty"} }

    // 访问元素
    std::cout << m1[10] << std::endl; // "ten"
    // 使用 at() 方法访问，如果键不存在会抛出异常
    try {
        std::cout << m1.at(100) << std::endl; // 抛出 out_of_range 异常
    } catch (const std::out_of_range& e) {
        std::cout << "Key 100 not found!" << std::endl;
    }


    // 查找元素
    auto it = m2.find(2);
    if (it != m2.end()) {
        std::cout << "Found: " << it->first << " -> " << it->second << std::endl; // Found: 2 -> two
    }

    // 遍历 (自动按键排序)
    for (const auto& pair : m1) {
        std::cout << pair.first << ": " << pair.second << " "; // 5: five 10: ten 15: fifteen 20: twenty
    }
    std::cout << std::endl;

    // 删除元素
    m1.erase(15); // 删除键为15的元素
    // m1 内容: { {5, "five"}, {10, "ten"}, {20, "twenty"} }

    for (const auto& pair : m1) {
        std::cout << pair.first << ": " << pair.second << " "; // 5: five 10: ten 20: twenty
    }
    std::cout << std::endl;

    std::cout << m1.empty() << std::endl; // 0

    // size, max_size, empty, clear
    // operator[], at
    // insert, erase
    // find, count (count always returns 0 or 1 for map), lower_bound, upper_bound, equal_range
    // swap, emplace, emplace_hint

    return 0;
}
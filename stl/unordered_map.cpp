#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
    std::unordered_map<int, std::string> um1; // 空无序映射
    // unordered_map 是键值对的集合，不按键排序，键唯一，基于哈希表实现
    std::unordered_map<int, std::string> um2 = {
        {1, "one"},
        {3, "three"},
        {2, "two"}
    };
    // um2 内容: { {1, "one"}, {3, "three"}, {2, "two"} } (顺序未指定)

    std::cout << um2.size() << std::endl; // 3

    // 插入/访问元素 (operator[] 如果键不存在会创建一个默认值)
    um1[10] = "ten";
    um1[20] = "twenty";
    // um1 内容: { {10, "ten"}, {20, "twenty"} } (顺序未指定)

    // 使用 insert 插入
    um1.insert(std::make_pair(15, "fifteen"));
    // 或者使用花括号列表 (C++11)
    um1.insert({5, "five"});
    // um1 内容: { {5, "five"}, {10, "ten"}, {15, "fifteen"}, {20, "twenty"} } (顺序未指定)

    // 访问元素
    std::cout << um1[10] << std::endl; // "ten"
    // 使用 at() 方法访问，如果键不存在会抛出异常
    try {
        std::cout << um1.at(100) << std::endl; // 抛出 out_of_range 异常
    } catch (const std::out_of_range& e) {
        std::cout << "Key 100 not found!" << std::endl;
    }

    // 查找元素 (平均 O(1)，最坏 O(n))
    auto it = um2.find(2);
    if (it != um2.end()) {
        std::cout << "Found: " << it->first << " -> " << it->second << std::endl; // Found: 2 -> two (键值对顺序未指定)
    }

    // 遍历 (顺序未指定)
    for (const auto& pair : um1) {
        std::cout << pair.first << ": " << pair.second << " "; // 例如: 20: twenty 5: five 10: ten 15: fifteen (具体顺序依赖实现)
    }
    std::cout << std::endl;

    // 删除元素
    um1.erase(15); // 删除键为15的元素
    // um1 内容: { {5, "five"}, {10, "ten"}, {20, "twenty"} } (顺序未指定)

    for (const auto& pair : um1) {
        std::cout << pair.first << ": " << pair.second << " "; // 例如: 20: twenty 5: five 10: ten
    }
    std::cout << std::endl;

    std::cout << um1.empty() << std::endl; // 0

    // size, max_size, empty, clear
    // operator[], at
    // insert, erase
    // find, count (count always returns 0 or 1 for unordered_map)
    // swap, emplace

    // bucket_count, max_bucket_count, bucket_size, load_factor, max_load_factor, rehash, reserve

    return 0;
}
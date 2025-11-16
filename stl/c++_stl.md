> 内容来自[geeksforgeeks](https://www.geeksforgeeks.org/cpp/cpp-stl-tutorial "C++ STL Tutorial")

> 大多数内容由qwen code生成

## pair:
```cpp
#include <iostream>
#include <utility>

int main()
{
    // 声明/初始化, 元素访问
    std::pair<int, std::string> p1 = {1, "cpp"};
    std::cout << p1.first << ": " << p1.second << std::endl; //1: cpp

    std::pair<int, std::string> p2 = std::make_pair(2, "rust");

    std::pair<int, std::string> p3;
    p3.first = 3;
    p3.second = "golang";

    // unpack
    auto [index, name] = p1;

    // compare。可以用比较运算符对两个pair进行比较，先比first元素，若相等再比second元素
    std::cout << std::boolalpha;
    std::cout << "p1 == p2: " << (p1 == p2) << "\n"; // false
    std::cout << "p1 != p2: " << (p1 != p2) << "\n"; // true
    std::cout << "p1 < p2: " << (p1 < p2) << "\n";   // true
    std::cout << "p1 <= p2: " << (p1 <= p2) << "\n"; // true
}
```

## vector:
```cpp
#include <iostream>
#include <list>

int main()
{
    std::list<int> l1;
    std::list<int> l2(2, 5);
    std::list<int> l3 = {1, 2, 3, 4, 5};

    std::cout << l3.front() << " " << l3.back() << " " << l3.size() << std::endl;

    l3.push_front(0);
    l3.push_back(6);

    // 0 1 2 3 4 5 6

    auto it = l3.begin(); // 0
    ++it; // 1
    l3.insert(it, 10); // 0 10 1 2 3 4 5 6

    advance(it, 3); // 4
    l3.erase(it); // 0 10 1 2 3 5 6

    std::cout << *next(l3.begin(), 2) << std::endl; // 1

    it = l3.begin(); // 0
    advance(it, 4); // 3
    *it = 4; // 0 10 1 2 4 5 6
    for (const auto& val : l3)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    it = std::find(l3.begin(), l3.end(), 10);
    std::cout << (it != l3.end()) << std::endl; // 1
    l3.erase(it); // 0 1 2 4 5 6
    for (const auto& val : l3)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    l3.pop_front(); // 1 2 4 5 6
    l3.pop_back(); // 1 2 4 5

    // size, empty, rbegin, rend, clear

    // emplace_front, emplace_back, emplace,
    // merge
    // remove, remove_if
    // unique, splice, swap, sort, reverse

    return 0;
}
```

## list: 双向链表
```cpp
#include <iostream>
#include <list>

int main()
{
    std::list<int> l1;
    std::list<int> l2(2, 5);
    std::list<int> l3 = {1, 2, 3, 4, 5};

    std::cout << l3.front() << " " << l3.back() << " " << l3.size() << std::endl;

    l3.push_front(0);
    l3.push_back(6);

    // 0 1 2 3 4 5 6

    auto it = l3.begin(); // 0
    ++it; // 1
    l3.insert(it, 10); // 0 10 1 2 3 4 5 6

    advance(it, 3); // 4
    l3.erase(it); // 0 10 1 2 3 5 6

    std::cout << *next(l3.begin(), 2) << std::endl; // 1

    it = l3.begin(); // 0
    advance(it, 4); // 3
    *it = 4; // 0 10 1 2 4 5 6
    for (const auto& val : l3)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    it = std::find(l3.begin(), l3.end(), 10);
    std::cout << (it != l3.end()) << std::endl; // 1
    l3.erase(it); // 0 1 2 4 5 6
    for (const auto& val : l3)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    l3.pop_front(); // 1 2 4 5 6
    l3.pop_back(); // 1 2 4 5

    // size, empty, rbegin, rend, clear

    // emplace_front, emplace_back, emplace,
    // merge
    // remove, remove_if
    // unique, splice, swap, sort, reverse

    return 0;
}
```

## forward_list 单向链表
```cpp
#include <iostream>
#include <forward_list>
#include <iterator> // For std::next, std::advance
#include <algorithm> // For std::find

int main()
{
    std::forward_list<int> fl1;
    std::forward_list<int> fl2(2, 5);
    std::forward_list<int> fl3 = {1, 2, 3, 4, 5};

    std::cout << fl3.front() << std::endl; // 1

    fl3.push_front(0); // 0 1 2 3 4 5

    auto it = fl3.before_begin();
    ++it;
    fl3.insert_after(it, 10); // 0 10 1 2 3 4 5 ; forward_list没有insert()

    it = fl3.before_begin();
    std::advance(it, 3);
    fl3.erase_after(it); // 删除 1 后面的元素 2, 结果: 0 10 1 3 4 5

    auto it2 = std::next(fl3.begin(), 2);
    *it2 = 99; // 0 10 99 3 4 5

    it = std::find(fl3.begin(), fl3.end(), 10);
    if (it != fl3.end()) {
        fl3.insert_after(it, 11); // 0 10 11 99 3 4 5
    }

    fl3.pop_front(); // 10 11 99 3 4 5

    // size, max_size, empty, clear

    // emplace_front, emplace_after
    // merge, remove, remove_if, unique, splice, sort, reverse, swap

    return 0;
}
```

## set:
```cpp
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
```

## map:
```cpp
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
```

## unordered_map:
```cpp
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
```

## string:
```cpp
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s1;
    std::string s2(5, 'a'); // "aaaaa"
    std::string s3 = "hello";

    std::cout << s3[0] << " " << s3.at(1) << " " << s3.size() << std::endl; // h e 5

    std::cout << s3.front() << " " << s3.back() << " " << s3.size() << std::endl; // h o 5

    s3 += " world";
    s3.append("!");
    s3.insert(s3.size() - 1, " XYZ"); // 在 '!' 前插入
    std::cout << s3 << std::endl; // "hello world XYZ!"

    for (const auto& ch : s3)
    {
        std::cout << ch;
    }
    std::cout << std::endl;

    s3.pop_back(); // 移除 '!'
    s3.erase(s3.size() - 4, 4); // 移除 " XYZ"
    std::cout << s3 << std::endl; // "hello world"

    std::cout << s3.empty() << std::endl; // 0

    // 拷贝一个 string
    std::string s4 = s3;
    std::string s5(s3);
    std::string s6;
    s6 = s3;

    std::vector<char> char_vec(s3.begin(), s3.end()); // 可以用迭代器构造 vector

    // find 相关
    std::string::size_type pos = s3.find("world");
    if (pos != std::string::npos) {
        std::cout << "Found 'world' at position: " << pos << std::endl; // Found 'world' at position: 6
    }

    // substr
    std::string sub = s3.substr(6, 5); // 从位置 6 开始，取 5 个字符
    std::cout << sub << std::endl; // "world"

    // c_str, data (获取 C 风格字符串指针)
    const char* c_str_ptr = s3.c_str();
    const char* data_ptr = s3.data(); // C++11 起保证与 c_str 相同

    // clear, size, length, capacity, max_size
    // emplace_back (C++11), push_back
    // compare, replace, swap

    return 0;
}
```

## deque:
```cpp
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
```

## queue:
```cpp
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
```

## stack:
```cpp
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
```

## heap:
```cpp
#include <iostream>
#include <vector>
#include <algorithm> // std::make_heap, std::push_heap, std::pop_heap, std::sort_heap
#include <functional> // std::greater

int main()
{
    // 使用 vector 作为堆的底层容器
    std::vector<int> heap = {3, 1, 4, 1, 5, 9, 2, 6};

    // make_heap 将一个范围转换为堆 (默认是最大堆)
    std::make_heap(heap.begin(), heap.end());
    // 此时 heap 满足堆的性质，但整体不是有序的
    std::cout << "After make_heap (max-heap): ";
    for (int val : heap) {
        std::cout << val << " "; // 输出顺序未指定，但满足堆性质 (最大值在 front)
    }
    std::cout << std::endl;
    std::cout << "Top element (max): " << heap.front() << std::endl; // 9 (最大值)

    // push_heap 需要先在容器末尾添加元素，然后调用 push_heap 维护堆性质
    heap.push_back(8); // 先添加到末尾
    std::push_heap(heap.begin(), heap.end()); // 调整堆
    std::cout << "After push_heap with 8: ";
    std::cout << "Top element (max): " << heap.front() << std::endl; // 9 或 8 (取决于 8 在哪里，但最大值仍在 front)

    // pop_heap 将堆顶元素移到容器末尾，并调整堆
    std::pop_heap(heap.begin(), heap.end()); // 将最大值移到末尾 (但并未真正删除)
    std::cout << "After pop_heap, heap size: " << heap.size() << std::endl;
    std::cout << "Max element is now at back: " << heap.back() << std::endl; // 原来最大的元素
    heap.pop_back(); // 真正删除
    std::cout << "After pop_back, new top: " << heap.front() << std::endl; // 新的最大元素

    // sort_heap 将堆排序成有序序列 (升序)
    std::vector<int> heap2 = {3, 1, 4, 1, 5, 9, 2, 6};
    std::make_heap(heap2.begin(), heap2.end());
    std::sort_heap(heap2.begin(), heap2.end());
    std::cout << "After sort_heap (sorted ascending): ";
    for (int val : heap2) {
        std::cout << val << " "; // 1 1 2 3 4 5 6 9
    }
    std::cout << std::endl;

    // 创建最小堆 (使用 greater 比较器)
    std::vector<int> min_heap = {3, 1, 4, 1, 5, 9, 2, 6};
    std::make_heap(min_heap.begin(), min_heap.end(), std::greater<int>{}); // 使用 greater
    std::cout << "Min-heap top: " << min_heap.front() << std::endl; // 1 (最小值)
    // 注意: 对最小堆使用 pop_heap 和 push_heap 时，仍需传入 greater 比较器
    min_heap.push_back(0);
    std::push_heap(min_heap.begin(), min_heap.end(), std::greater<int>{});
    std::cout << "After pushing 0 to min-heap, new top: " << min_heap.front() << std::endl; // 0

    // is_heap 检查范围是否为堆
    std::cout << "Is original vector a heap? " << std::is_heap(heap.begin(), heap.end()) << std::endl; // 0 (false, 因为已经 pop 过)
    std::vector<int> test_heap = {9, 5, 6, 1, 4, 3, 2};
    std::cout << "Is {9,5,6,1,4,3,2} a max-heap? " << std::is_heap(test_heap.begin(), test_heap.end()) << std::endl; // 1 (true)

    // make_heap, push_heap, pop_heap, sort_heap, is_heap
    // is_heap_until

    return 0;
}
```

## STL容器方法对比表

为了方便对比各个容器的方法和特性，以下是一个总结表格：

| Method/Container | vector | deque | list | forward_list | queue | stack | set | map | unordered_set | unordered_map |
|------------------|--------|-------|------|--------------|-------|-------|-----|-----|---------------|---------------|
| **Basic Methods** |  |  |  |  |  |  |  |  |  |  |
| size() | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| empty() | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| clear() | ✓ | ✓ | ✓ | ✓ | ✗ | ✗ | ✓ | ✓ | ✓ | ✓ |
| **Access Methods** |  |  |  |  |  |  |  |  |  |  |
| operator[] | ✓ | ✓ | ✗ | ✗ | ✗ | ✗ | ✗ | ✓* | ✗ | ✓* |
| at() | ✓ | ✓ | ✗ | ✗ | ✗ | ✗ | ✗ | ✓ | ✗ | ✓ |
| front() | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | ✗ | ✗ | ✗ | ✗ |
| back() | ✓ | ✓ | ✓ | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ | ✗ |
| **Insertion Methods** |  |  |  |  |  |  |  |  |  |  |
| push_front() | ✗ | ✓ | ✓ | ✓ | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ |
| push_back() | ✓ | ✓ | ✓ | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ | ✗ |
| insert() | ✓ | ✓ | ✓ | ✗* | ✗ | ✗ | ✓ | ✓ | ✓ | ✓ |
| emplace_front() | ✗ | ✓ | ✓ | ✓ | ✗ | ✗ | ✓ | ✓ | ✓ | ✓ |
| emplace_back() | ✓ | ✓ | ✓ | ✗ | ✗ | ✗ | ✓ | ✓ | ✓ | ✓ |
| emplace() | ✓ | ✓ | ✓ | ✗ | ✗ | ✗ | ✓ | ✓ | ✓ | ✓ |
| **Deletion Methods** |  |  |  |  |  |  |  |  |  |  |
| pop_front() | ✗ | ✓ | ✓ | ✓ | ✓ | ✗ | ✗ | ✗ | ✗ | ✗ |
| pop_back() | ✓ | ✓ | ✓ | ✗ | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| erase() | ✓ | ✓ | ✓ | ✗* | ✗ | ✗ | ✓ | ✓ | ✓ | ✓ |
| **Iterator Support** |  |  |  |  |  |  |  |  |  |  |
| begin()/end() | ✓ | ✓ | ✓ | ✓ | ✗ | ✗ | ✓ | ✓ | ✓ | ✓ |
| rbegin()/rend() | ✓ | ✓ | ✓ | ✗ | ✗ | ✗ | ✓ | ✓ | ✓ | ✓ |
| **Search Methods** |  |  |  |  |  |  |  |  |  |  |
| find() | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ | ✓ | ✓ | ✓ | ✓ |
| count() | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ | ✓ | ✓ | ✓ | ✓ |
| lower_bound/upper_bound | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ | ✓ | ✓ | ✗ | ✗ |
| **Special Methods** |  |  |  |  |  |  |  |  |  |  |
| capacity() | ✓ | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ |
| reserve() | ✓ | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ |
| resize() | ✓ | ✓ | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ |
| merge() | ✗ | ✗ | ✓ | ✓ | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ |
| remove()/remove_if() | ✗ | ✗ | ✓ | ✓ | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ |
| unique() | ✗ | ✗ | ✓ | ✓ | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ |
| sort() | ✗ | ✗ | ✓ | ✓ | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ |
| reverse() | ✗ | ✗ | ✓ | ✓ | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ |
| splice() | ✗ | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ | ✗ |

*注：
- forward_list 提供 insert_after() 和 erase_after() 方法，而非 insert() 和 erase()
- map 和 unordered_map 的 operator[] 允许通过键访问/创建元素
- queue、stack 是适配器容器，接口有限，但提供了特定的功能
- set 和 map 是有序关联容器，unordered_set 和 unordered_map 是无序关联容器
- 关联容器（set、map、unordered 系列）提供了专门的查找方法如 find()、count()

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v1;

    std::vector<int> v2(2, 5); // 2个元素，每个元素值为5

    std::vector<int> v3 = {1, 2, 3, 4, 5};
    // at会检查边界，如果越界会抛出异常
    std::cout << v3[0] << " " << v3.at(1) << " " << v3.size() << std::endl;

    std::cout << v3.front() << " " << v3.back() << " " << v3.size() << std::endl;

    v3.push_back(6);
    v3.insert(v3.begin(), 0);
    v3.insert(v3.end(), 7);
    v3.insert(v3.begin() + v3.size(), 8);
    // 0 1 2 3 4 5 6 7 8
    for (const auto& val : v3)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 0 1 2 3 4 5 6 7 8
    for (auto it = v3.begin(); it != v3.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    v3.pop_back();
    v3.erase(v3.begin());
    // 1 2 3 4 5 6 7
    for (const auto& val : v3)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << v3.empty() << std::endl;;

    std::vector<std::vector<int>> matrix;

    // 拷贝一个vector
    std::vector<int> v4 = v3;
    std::vector<int> v5(v3);
    std::vector<int> v6;
    copy(v3.begin(), v3.end(), std::back_inserter(v6));
    std::vector<int> v7;
    v7.assign(v3.begin(), v3.end());
    // use insert, push_back

    // capacity, reserve, resize, shrink_to_fit
    // emplace_front, emplace_back, emplace 当vector元素比较复杂时，使用emplace来替换insert
    // 相比于list， vector没有merge, remove, remove_if, unique, splice, swap, sort, reverse等方法
}
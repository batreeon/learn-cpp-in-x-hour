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
    // merge, remove, remove_if, unique, sort, reverse, swap

    return 0;
}
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
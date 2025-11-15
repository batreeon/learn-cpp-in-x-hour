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
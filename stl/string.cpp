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
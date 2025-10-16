#include <iostream>
#include <iterator>
#include <string>

int main() {
    std::ostream_iterator<std::string> oo {std::cout};

    *oo = "hello, ";
    ++oo;
    *oo = "world!\n";

    std::string from, to;
    std::cin >> from >> to;
}
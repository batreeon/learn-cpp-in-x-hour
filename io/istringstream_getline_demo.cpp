#include <iostream>
#include <string>
#include <sstream>

int main() {
    // Example 1: Basic usage of istringstream
    std::cout << "=== Basic istringstream usage ===" << std::endl;
    std::string input = "Hello World 123";
    std::istringstream iss(input);
    
    std::string word1, word2;
    int number;
    
    iss >> word1 >> word2 >> number;
    
    std::cout << "Extracted word1: '" << word1 << "'" << std::endl;
    std::cout << "Extracted word2: '" << word2 << "'" << std::endl;
    std::cout << "Extracted number: " << number << std::endl;
    
    std::cout << std::endl;
    
    // Example 2: Using getline with istringstream
    std::cout << "=== getline with istringstream ===" << std::endl;
    std::string csv_line = "John,Doe,25,Engineer";
    std::istringstream csv_stream(csv_line);
    
    std::string field;
    std::cout << "Fields extracted using getline with comma delimiter:" << std::endl;
    
    while (std::getline(csv_stream, field, ',')) {
        std::cout << "  '" << field << "'" << std::endl;
    }
    
    std::cout << std::endl;
    
    // Example 3: Using getline with default delimiter (newline)
    std::cout << "=== getline with default delimiter (newline) ===" << std::endl;
    std::string multi_line = "Line 1\nLine 2\nLine 3";
    std::istringstream line_stream(multi_line);
    
    std::string line;
    std::cout << "Lines extracted using getline with default delimiter:" << std::endl;
    
    while (std::getline(line_stream, line)) {
        std::cout << "  '" << line << "'" << std::endl;
    }
    
    std::cout << std::endl;
    
    // Example 4: Demonstrating multiple getline calls
    std::cout << "=== Multiple getline calls ===" << std::endl;
    std::string text = "first;second;third;fourth";
    std::istringstream semicolon_stream(text);
    
    std::string part1, part2, part3, part4;
    
    std::getline(semicolon_stream, part1, ';');
    std::getline(semicolon_stream, part2, ';');
    std::getline(semicolon_stream, part3, ';');
    std::getline(semicolon_stream, part4); // No delimiter specified, reads to end
    
    std::cout << "Part 1: '" << part1 << "'" << std::endl;
    std::cout << "Part 2: '" << part2 << "'" << std::endl;
    std::cout << "Part 3: '" << part3 << "'" << std::endl;
    std::cout << "Part 4: '" << part4 << "'" << std::endl;
    
    return 0;
}
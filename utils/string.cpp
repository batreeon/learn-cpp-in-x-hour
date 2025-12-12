#include <iostream>
#include <string>

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    // 输入流
    std::istringstream tokenStream(str);

    // 从tokenStream中提取元素
    while (std::getline(tokenStream, token, delimiter)) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    return tokens;
}


std::vector<std::string> split(const std::string &s, const std::string &delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = s.find(delimiter);
    
    while (end != std::string::npos) {
        std::string token = s.substr(start, end - start);
        // 可选：忽略空字符串
        if (!token.empty()) {
            tokens.push_back(token);
        }
        start = end + delimiter.length();
        end = s.find(delimiter, start);
    }
    
    // 添加最后一个子字符串
    std::string lastToken = s.substr(start);
    if (!lastToken.empty()) {
        tokens.push_back(lastToken);
    }
    
    return tokens;
}

// 
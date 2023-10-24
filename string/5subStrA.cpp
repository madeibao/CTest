



#include <iostream>
#include <string>
 
int main() {
    std::string str = "Hello, World!";
    
    // 提取从位置 7 开始的子串
    std::string sub1 = str.substr(7);
    std::cout << "sub1: " << sub1 << std::endl;  // 输出 "World!"
    
    // 提取从位置 7 开始的长度为 5 的子串
    std::string sub2 = str.substr(7, 5);
    std::cout << "sub2: " << sub2 << std::endl;  // 输出 "World"
    
    return 0;
}

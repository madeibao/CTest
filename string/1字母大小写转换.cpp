


// 字符串大小写转换

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

int main(int argc, char** argv) {

	string s= "HELLO";
	// 小写
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	cout << s << endl;
	// 大写
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	cout << s << endl;
	return 0;
}





A的ASSCII值是65，那么zhi小写a就是65+32=97


	A 65
	a 97


#include <iostream>  
#include <string>  
  
int main() {  
    std::string str = "Hello, world!";  
      
    // 查找字符 'o'  
    size_t pos = str.find('o');  
    if (pos != std::string::npos) {  
        std::cout << "'o' found at position: " << pos << '\n';  
    } else {  
        std::cout << "'o' not found\n";  
    }  
      
    return 0;  
}






// Java 内存模型

// reenLock

// Synchronized

// Java 线程池
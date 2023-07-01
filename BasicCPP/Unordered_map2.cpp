
// unordered_map::count

// unordered_map 的 count 用法

#include <iostream>
#include <string>
#include <unordered_map>

int main () {

    std::unordered_map<std::string,double> mymap = {
        {"Burger",2.99},
        {"Fries",1.99},
        {"Soda",1.50},
    };

    for (auto& x: {"Burger","Pizza","Salad","Soda"}) {
        if (mymap.count(x)>0)
            std::cout << "mymap has " << x << std::endl;
        else
            std::cout << "mymap has no " << x << std::endl;
    }

    std::cout<<"------------------------------------"<<std::endl;
    // unorder_map中的find函数是查找key所对应的value的位置（迭代器）。
    std::unordered_map<char, int>mp1{ {'a',1},{'b',2},{'c',3} };
    char c = 'a';
    char d = 'd';
    std::unordered_map<char, int>::iterator it;

    it = mp1.find(c);
    if (it == mp1.end())
        std::cout << "not found" << std::endl;
    else
        std::cout << it->first << "  " << it->second << std::endl;
        
    it = mp1.find(d);
    if (it == mp1.end())
        std::cout << "not found" << std::endl;
    else
        std::cout << it->first << "  " << it->second << std::endl;

    return 0;
}



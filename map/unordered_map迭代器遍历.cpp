

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    //创建并初始化一个 unordered_map 容器，其存储的 <string,string> 类型的键值对
    std::unordered_map<std::string, std::string> my_uMap{
        {"C语言教程","http://c.biancheng.net/c/"},
        {"Python教程","http://c.biancheng.net/python/"},
        {"Java教程","http://c.biancheng.net/java/"} };
    //查找指定键对应的值，效率比关联式容器高
    string str = my_uMap.at("C语言教程");
    cout << "str = " << str << endl;

    //使用迭代器遍历哈希容器，效率不如关联式容器
    for (auto iter = my_uMap.begin(); iter != my_uMap.end(); ++iter)
    {
        //pair 类型键值对分为 2 部分
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}

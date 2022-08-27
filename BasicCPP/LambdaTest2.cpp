

lambda表达式
ambda 表达式定义了一个匿名函数，并且可以捕获一定范围内的变量。lambda 表达式的语法形式可简单归纳如下：

[ capture ] ( params ) opt -> ret { body; };
其中 capture 是捕获列表，params 是参数表，opt 是函数选项，ret 是返回值类型，body是函数体。

因此，一个完整的 lambda 表达式看起来像这样：

auto f = [](int a) -> int { return a + 1; };
std::cout << f(1) << std::endl;  // 输出: 2




#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    auto f = [](int a) -> int { return a + 1; };
    cout << f(1) << endl;  // 输出: 2

    return 0;
}

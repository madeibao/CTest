

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,5};
    vector<int> varr(arr, arr+5);
    for(auto i:varr) {
        cout<<i<<" "<<endl;
    }
    return 0;
}

// --------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <iterator>
using std::vector;
using std::begin;
using std::end;
using std::cout;
using std::endl;
  	
int main() {
    int arr[] = {11, 32, 41, 25, 67, 100, 88, 233};  // 列表初始化内置数组  
    // 指出拷贝区域范围，使用数组初始化 vector 对象
    vector<int> iv(begin(arr), end(arr));
  		
    for (auto c : iv)  // 输出 vector 对象的内容以验证结果
        cout << c << ' ';
    cout << endl;
  		
    return 0;
}

// -------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <iterator>
using std::vector;
using std::begin;
using std::end;
using std::cout;
using std::endl;
  	
int main()
{
    int arr[] = {11, 32, 41, 25, 67, 100, 88, 233};  // 列表初始化内置数组  
    // 指出拷贝区域范围，使用数组初始化 vector 对象
    vector<int> iv(begin(arr), end(arr));
  		
    for (auto c : iv)  // 输出 vector 对象的内容以验证结果
        cout << c << ' ';
    cout << endl;
  		
    return 0;
}

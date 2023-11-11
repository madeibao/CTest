

#include <iostream>
#include <vector>
using namespace std;

int main() {

  /*
   *  1. assign的range用法，使用迭代器，将另一个容器的值赋值给目标容器
   *     注意：不会改变原始容器的值（即下面容器v1的值）； 会清除目标容器的所有值，再进行赋值
   */
  cout << "*** assign 的range用法 " << endl;
  vector<int> v1 = {1, 2, 3, 4, 5, 6};
  vector<int> v2;
  v2.assign(v1.begin(), v1.end());
  for (const auto p : v2) {
    cout << p << " ";
  }
  cout << endl;


  /*
   *  2. assign的fill用法，用 n 个值为 val 的元素填充目的容器
   */
  cout << "*** assign 的fill用法 " << endl;
  std::vector<int> v3;
  v3.assign(6, 1);
  for (const auto p : v3) {
    cout << p << " ";
  }
  cout << endl;


  /*
   *  3. assign的 initializer list版本就是C++ 11的新特性初始化列表的应用
   */
  cout << "*** assign 的 initializer list用法 " << endl;
  std::vector<int> v4;
  v4.assign({6, 5, 4, 3, 2, 1});
  for (const auto p : v4) {
    cout << p << " ";
  }
  cout << endl;

  return 0;
}

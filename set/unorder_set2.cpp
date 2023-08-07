

Unodered Set
无序集(unorder sets)是一种不按特定顺序存储唯一元素的容器，允许根据元素的值快速检索单个元素。

在unordered_set中，元素的值同时也是唯一标识它的键。键是不可变的，因此，unordered_set中的元素在容器中不能被修改，但是它们可以被插入和删除。

在内部，unordered_set中的元素并不按照任何特定的顺序排序，而是根据它们的散列值组织到桶中，
从而允许根据它们的值直接快速访问单个元素(平均时间复杂度为常数)。

与set容器相比，Unordered_set容器通过键访问单个元素的速度更快，尽管它们通常在通过元素的子集进行范围迭代时效率较低。


#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{

    unordered_set<int> set1({ 3, 7, 5, 9, 0, 1, 6 });

    auto it = set1.begin();

    while (it != set1.end())
    {
        cout << *it << "  ";
        it++;
    }
    cout << endl;

    return 0;
}

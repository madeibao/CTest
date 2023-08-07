

通常，set<T> 容器内部元素的组织方式和 map<K，T> 相同，都是平衡二叉树。
请考虑下面这个 set 容器的定义，可以用初始化列表来初始化 set 容器：
std::set<int> numbers {8, 7, 6, 5, 4, 3, 2, 1};
默认的比较函数是 less<int>，因此容器中的元素会升序排列。内部的二叉树和图 1 中所示的类似。


// 默认是升序
#include <stdio.h>
#include <set>
using namespace std;

int main() {
    set<int> st;
    st.insert(3); //insert（x）将x插入set中
    st.insert(5);
    st.insert(2);
    st.insert(3);
    //注意，不支持it＜ st（）的写法
    for(set<int>::iterator it=st.begin();it!=st.end();it++){
        printf("%d", *it);
    }
    return 0;
}




// 修改为降序

#include <iostream>
#include <set>
#include <ctime>
#include <algorithm>
using namespace std;

class Mycompare
{
public:

	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};

void setpoo()
{
	srand((unsigned int)time(NULL));
	set<int, Mycompare>s;
	//赋值
	for (int i = 0; i < 10; i++)
	{
		s.insert(rand() % 10 + 20);
	}
	//遍历
	set<int, Mycompare>::iterator sit;
	sit = s.begin();
	for (; sit != s.end(); sit++)
	{
		cout << *sit << " ";
	}
	cout << endl;
}
int main()
{
	setpoo();
	system("pause");
	return 0;
}


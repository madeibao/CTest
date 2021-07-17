

#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<vector<int>> A;
    vector<int> B;

    B.push_back(0);
    B.push_back(1);
    B.push_back(2);
    B.push_back(3);
    A.push_back(B);

    //注意需要清空B
    B.clear();
    B.push_back(4);
    B.push_back(5);
    B.push_back(6);
    B.push_back(7);
    A.push_back(B);

    cout << "============第一种索引方式============" << endl;
    for (int i = 0; i < 2; i++)
    {
        vector<int> & p = A[i];
        for (int j = 0; j < p.size(); j++)
        {
            cout << p[j] << " ";
        }
        cout << endl;
    }

    cout << "============第二种索引方式============" << endl;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size();j++)
            cout << A[i][j] << " ";

        cout << endl;
    }

    return  0;
}

#====================================================================
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> vecTest;
    vector<int> vec_int;

    vec_int.push_back(0);
    vec_int.push_back(1);
    vec_int.push_back(2);
    vec_int.push_back(3);

    vecTest.push_back(vec_int);

    auto iter = vecTest.begin();
    for(int i = 0;i<vec_int.size();++i)
    {
        cout << (*iter)[i] << endl;
    }
    return 0;



}

int vec3() {
    //顺序访问
    vector<int>obj;
    for(int i=0;i<10;i++)
    {
        obj.push_back(i);
    }

    cout<<"直接利用数组：";
    for(int i=0;i<10;i++)       //方法一
    {
        cout<<obj[i]<<" ";
    }
    cout<<endl;
    cout<<"利用迭代器。" ;
    //方法二，使用迭代器将容器中数据输出
    vector<int>::iterator it;       //声明一个迭代器，来访问vector容器，作用：遍历或者指向vector容器的元素
    for(it=obj.begin();it!=obj.end();it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}



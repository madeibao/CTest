


#include <iostream>
using namespace std;

class Array{
public:
    Array(int len); // 构造函数，传入数组长度，申请内存空间
    Array(const Array &arr); // 拷贝构造函数，深拷贝，另开辟内存空间
    ~Array(); // 析构函数，释放内存空间

    int operator[](int i) const{ return m_p[i]; } // 重载[]，用来读取数组变量
    int &operator[](int i) { return m_p[i]; } // 重载[]，用来写入数组变量
    int length() const { return this->m_len; }
    void display();
private:
    int m_len;
    int *m_p;
};

Array::Array(int len): m_len(len) {
    m_p = new int[len];
}

Array::Array(const Array &arr) {
    this->m_len = arr.m_len;
    this->m_p = new int[this->m_len];
    memcpy(this->m_p, arr.m_p, sizeof(int) * this->m_len);
}

Array::~Array() {
    delete[] this->m_p;
    this->m_p = NULL;
}

void Array::display() {
    for (int i=0; i<this->m_len; i++) {
        if (i == this->m_len - 1) {
            cout << *(m_p + i) << endl;
        }
        else {
            cout << *(m_p + i) << " ";
        }
    }
}

int main() {
    Array arr1(5);
    for (int i=0; i<arr1.length(); i++) {
        arr1[i] = i+10;
    }

    cout << "arr1: \n";
    arr1.display();

    Array arr2 = arr1;
    arr2[3] = 100;
    cout << "arr2: \n";
    arr2.display();

    // 不会改变 arr1 
    cout << "arr1: \n";
    arr1.display();
    return 0;
}

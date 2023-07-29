

#include<iostream>

class Point {
private:
	int _x;
	int _y;
public:
	Point() {

	}

	Point(int x, int y) : _x(x), _y(y) {

	}

	void Show() {
		std::cout << "(" << _x << "," << _y << ")" << std::endl;
	}

	// 运算符重载
    Point operator+ (const Point& p) {
        Point temp;
        temp._x = this->_x + p._x;
        temp._y = this->_y + p._y;
        return temp;
    }
};

int main() {
	Point p1(1, 1);
	Point p2(2, 2);
	p1.Show();
	p2.Show();

	// 隐士调用
//	Point p3 = p1+p2;

	// 显示调用
	Point p3 = p1.operator+(p2);
	p3.Show();


	return 0;
}



#include "iostream"
#include "bits/stdc++.h"

using namespace std;

int main(int argc, char **argv) {

	map<int, int> map2;

	map2.insert({1,1});
	map2.insert({2,12});
	map2.insert({3,14});

	map2.insert({4,5});
	map2.insert({6,7});
	map2.insert({8,9});
	map2.insert({10,11});
	map2.insert({12,13});
	map2.insert({14,15});
	map2.insert({16,17});
	map2.insert({18,19});
	map2.insert({20,21});
	map2.insert({22,23});


    // 遍历map2，方式一
    cout << "方式一：" << endl;
    map<int, int>::iterator it;
    for (it = map2.begin(); it != map2.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    cout << "----------------------------------------------------------------" << endl;

    // 遍历map2，方式二
    cout << "方式二：" << endl;
    for (auto i : map2) {
        cout << i.first << " " << i.second << endl;
    }
	


	map2.erase(22); // 删除 map 中一个键

	return 0;
}

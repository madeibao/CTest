


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int StrToInt(string str)
{
    if (str[str.size() - 1] == 'M') {
        return stoi(str.substr(0, str.size() - 1));
    } else if (str[str.size() - 1] == 'G') {
        return stoi(str.substr(0, str.size() - 1)) * 1000;
    } else if (str[str.size() - 1] == 'T') {
        return stoi(str.substr(0, str.size() - 1)) * 1000000;
    }

    return 0;
}

bool Compare(const string &strA, const string &strB)
{
    int a = StrToInt(strA);
    int b = StrToInt(strB);

    // 升序排序
    return a < b;
}

int  main(void)
{
    int n;
    while (cin >> n) {
        string str;
        vector<string> vec;

        while (n--) {
            cin >> str;
            vec.push_back(str);
        }

        sort(vec.begin(), vec.end(), Compare);

        for (auto i : vec) {
            cout << i << endl;
        }
    }
    
    return 0;
}


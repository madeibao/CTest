

#include <bits/stdc++.h>
using namespace std;
int main() {
    int num = 0;
    cin >> num;
    vector<int>a;
    vector<int>ab;
    int tmp = 0;
    while (cin >> tmp) {
        a.push_back(tmp);
        if (cin.get() == '\n')
            break;
    }
    int i = 0,j = 1,k = 2;
    while (a[i] + a[j] + a[k] != num) {
            k++;
        if (a[i] + a[j] + a[k] != num)
            j++;
        if (a[i] + a[j] + a[k] != num)
            i++;
            }
    if (a[i] + a[j] + a[k] == num) {
            cout << '['<<a[i]<<',' << a[j]<<',' << a[k]<<']';
            }
    else if (a[i] + a[j] + a[k] > num) {
            return -1;
        }
}

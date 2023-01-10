

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    vector<int> input({1,2,3,4,5});
    int arr[input.size()];

    copy(input.begin(),input.end(),arr);
    for(int i:arr) {
        cout<<i<<endl;
    }
    return 0;
}

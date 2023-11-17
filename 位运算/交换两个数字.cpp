

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] = numbers[0] ^ numbers[1];
        numbers[1] = numbers[0] ^ numbers[1];
        numbers[0] = numbers[0] ^ numbers[1];
        return numbers;
    }
};

int main() {

    vector<int> numbers = {1,2};
    Solution s2;
    vector<int> result;
    result = s2.swapNumbers(numbers);
    for(auto i = 0; i < result.size();i++) {
        cout<<result[i]<<" "<<endl;
    }
    return 0;
}

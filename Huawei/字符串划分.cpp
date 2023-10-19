

#include <iostream>
#include <vector>
using namespace std;

void solution(string str) {
    int n = str.length();

    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + str[i];
    }

    int i = 1, j = 2;
    while (j < n) {
        int asciiSumI = prefixSum[i] - prefixSum[0];
        int asciiSumJ = prefixSum[j] - prefixSum[i + 1];
        int asciiSumK = prefixSum[n] - prefixSum[j + 1];

        if (asciiSumI == asciiSumJ && asciiSumJ == asciiSumK) {
            cout << i << "," << j << endl;
            return;
        }

        if (asciiSumI <= asciiSumJ) {
            i++;
        } else {
            j++;
        }
    }

    cout << "0,0" << endl;
}

int main() {
    string str;
    cin >> str;
    solution(str);
    return 0;
}
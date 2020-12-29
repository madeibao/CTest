

// 与leetcode84 的题目是相似的。




#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
int solution(vector<int>& width, vector<int>& height) {
    if(width.empty() || height.empty() || width.size() != height.size()){
        return 0;
    }

    int ans = 0;
    for(int i=0; i<width.size(); ++i) {
        if(width[i] <1 || width[i] > 100 || height[i] <1 || height[i] > 100){
            return 0;
        }

        int sum = width[i] * height[i];
        for(int k = i-1; k>=0 && height[k] >= height[i]; --k){
            sum += width[k] * height[i];
        }
        for(int k = i+1; k<width.size() && height[k] >= height[i]; ++k){
            sum += width[k] * height[i];
        }

        ans = max(ans, sum);
    }
    return ans;
}
int main(){
    string sw, sh;

    getline(cin, sw, ']');
    getline(cin, sh, ']');

    vector<int> width, height;
    istringstream issw(sw.substr(1));
    istringstream issh(sh.substr(2));

    string n;
    while(getline(issw, n, ',')){
        width.push_back(stoi(n));
    }
    while(getline(issh, n, ',')){
        height.push_back(stoi(n));
    }

    cout << solution(width, height) << endl;
    return 0;

}

// [1,1,1,1,2,1,1],[5,2,5,4,5,1,6]






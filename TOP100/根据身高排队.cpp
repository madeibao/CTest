

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

// 版本二
class Solution {
public:
    // 身高从大到小排（身高相同k小的站前面）
    static bool cmp(const vector<int> a, const vector<int> b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort (people.begin(), people.end(), cmp);
        list<vector<int>> que; // list底层是链表实现，插入效率比vector高的多
        for (int i = 0; i < people.size(); i++) {
            int position = people[i][1]; // 插入到下标为position的位置
            std::list<vector<int>>::iterator it = que.begin();
            while (position--) { // 寻找在插入位置
                it++;
            }
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};


int main(int argc, char** argv) {

	// vector<vector<int> > people = {{7,0],[4,4],[7,1],[5,0],[6,1],[5,2}};
	vector<vector<int> > people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
	vector<vector<int> > res;
	Solution solution;
	res = solution.reconstructQueue(people);
	for(auto i:res) {
		for(auto j: i) {
			cout << j<<" "<<;
		}
		cout << endl;
	}
	return 0;
}
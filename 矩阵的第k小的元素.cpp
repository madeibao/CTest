




class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                pq.push(matrix[i][j]);
                if (pq.size() > k) pq.pop();
            }
        }
        return pq.top();
    }
};



int main(int argc, char* argv[]) {
	vector<vector<int>> res = {{1,5,9},{10,11,13},{12,13,15}};
	Solution s;
	cout<<s.kthSmallest(res,8)<<endl;
	return 0;
}
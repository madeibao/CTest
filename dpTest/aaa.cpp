



class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>f(matrix[0]);
        for(int i=1;i<n;i++){
            int t=f[0];
            f[0]=matrix[i][0]+min(f[0],f[1]);
            for(int j=1;j<n-1;j++){
                int t2=f[j];
                f[j]=matrix[i][j]+min(t,min(t2,f[j+1]));
                t=t2;
            }
            f[n-1]=matrix[i][n-1]+min(t,f[n-1]);
        }
        return *min_element(f.begin(),f.end());
    }
};


int main() {


	return 0;
}




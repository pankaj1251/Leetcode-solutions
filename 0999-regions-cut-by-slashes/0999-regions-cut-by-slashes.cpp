class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &Matrix){
        if(min(i, j)<0 || max(i, j)>=Matrix.size() || Matrix[i][j]!=0)return 0;

        Matrix[i][j]=1;

        return 1 + dfs(i+1, j, Matrix) + dfs(i-1, j, Matrix) + dfs(i, j+1, Matrix) + dfs(i, j-1, Matrix);
    }

    int regionsBySlashes(vector<string>& arr) {
        int n = arr.size();
        int ans=0;

        vector<vector<int>>Matrix(n*3, vector<int>(n*3, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j]=='/'){
                    Matrix[i*3][j*3+2] = Matrix[i*3+1][j*3+1] = Matrix[i*3+2][j*3] = 1;
                }
                else if(arr[i][j]=='\\'){
                    Matrix[i*3][j*3] = Matrix[i*3+1][j*3+1] = Matrix[i*3+2][j*3+2] = 1;
                }
            }
        }

        for(int i=0; i<n*3; i++){
            for(int j=0; j<n*3; j++){
                    ans += dfs(i, j, Matrix)?1:0;
            }
        }

        return ans;
    }
};
class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        bool isZeroCol = false;
        bool isZeroRow = false;
        int n = arr.size(), m = arr[0].size();

        for (int i = 0; i < n; i++) {
            if (arr[i][0] == 0) {
                isZeroCol = true;
                break;
            } 
        }
        for (int i = 0; i < m; i++) { 
            if (arr[0][i] == 0) {
                isZeroRow = true;
                break;
            } 
        }
        for (int i = 1; i < n; i++) { 
            for (int j = 1; j < m; j++) 
                if (arr[i][j] == 0) {
                    arr[i][0] = 0;
                    arr[0][j] = 0;
                }
        }
        for (int i = 1; i < n; i++) { 
           for (int j = 1; j < m; j++) 
               if (arr[i][0] == 0 || arr[0][j] == 0)
                   arr[i][j] = 0;
        }
        if (isZeroCol) {
            for (int i = 0; i < n; i++) 
                arr[i][0] = 0;
        }
        if (isZeroRow) {
            for (int i = 0; i < m; i++) 
                arr[0][i] = 0;
        }
    }
};
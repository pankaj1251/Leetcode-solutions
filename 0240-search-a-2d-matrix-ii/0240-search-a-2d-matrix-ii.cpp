class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        int i=0, j=m-1; //we are starting from j=m-1 bc, array is sorted in ascending order so if target is greater than the last element of that row, then this row does not contain the target, so we go to next row.

        while(i<n && j>=0){
            if(matrix[i][j]==target)return true;
            else if(matrix[i][j]<target)i++;
            else j--;
        }

        return false;
    }
};
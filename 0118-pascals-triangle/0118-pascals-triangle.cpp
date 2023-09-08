class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>arr(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            arr[i][0]=1;
        }

        if(n==1)return {{1}};
        int k=2;
        for(int i=1; i<n; i++){
            for(int j=1; j<k; j++){
                if(i-1>=0) arr[i][j] += arr[i-1][j];
                arr[i][j] += arr[i-1][j-1];
            }
            k++;
        }

        vector<vector<int>>ans;

        for(int i=0; i<n; i++){
            vector<int>temp;
            for(int j=0; j<n; j++){
                if(arr[i][j]==0)break;
                temp.push_back(arr[i][j]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
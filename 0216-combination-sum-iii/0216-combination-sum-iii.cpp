class Solution {
public:
    vector<vector<int>> ans;

    void comsum(vector<int> &arr, int k, int n, int sum, int index){
        if(arr.size()==k && sum == n){
            ans.push_back(arr);
            return;
        }

        if(arr.size()>k || sum>n)
            return;
        
        for(int i = index; i <= 9; i++){
            sum += i;
            arr.push_back(i);
            comsum(arr, k, n, sum, i+1);
            sum -= i;
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        comsum(arr, k, n, 0, 1); //index starts from 1 as numbers are from 1 to 9.
        return ans;
    }
};
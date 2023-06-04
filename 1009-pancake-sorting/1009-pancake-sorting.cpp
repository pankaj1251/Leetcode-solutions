class Solution {
public:

    // void rec(vector<int>& arr, int idx, vector<int> &ans){
    //     if(idx==0)return;

    //     int maxm=INT_MIN;
    //     int index = -1;

    //     for(int i=0; i<idx; i++){
    //         if(arr[i]>maxm){
    //             maxm = arr[i];
    //             index=i;
    //         }
    //     }   
    //     reverse(arr.begin(), arr.begin()+index);
    //     reverse(arr.begin(), arr.end());
    //     ans.push_back(index+1);
    //     rec(arr, idx-1, ans);
    // }

    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans, temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());
        
        for(int i=n; i>0; i--){
            int maxm=INT_MIN;
            int index = -1;
            
            if(arr==temp)break;

            for(int j=0; j<i; j++){
                if(arr[j]>maxm){
                    maxm = arr[j];
                    index=j;
                }
            }
            
            ans.push_back(index+1);
            reverse(arr.begin(), arr.begin()+index+1);
            reverse(arr.begin(), arr.begin()+i);
            ans.push_back(i);
        }

        return ans;

    }
};
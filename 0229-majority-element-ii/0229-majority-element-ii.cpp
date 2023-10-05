class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();

        int num1=-1, num2=-1, c1=0, c2=0;

        for(int i=0; i<n; i++){
            if(arr[i]==num1)c1++;
            else if(arr[i]==num2)c2++;
            else if(c1==0)num1=arr[i], c1=1;
            else if(c2==0)num2=arr[i], c2=1;
            else c1--, c2--;
        }

        c1=0, c2=0;

        for(auto &it: arr){
            if(it==num1)c1++;
            else if(it==num2)c2++;
        }

        vector<int>ans;
        if(c1>n/3)ans.push_back(num1);
        if(c2>n/3)ans.push_back(num2);

        return ans;
    }
};
class Solution {
public:
    //can we do it using quick select?
    void wiggleSort(vector<int>& arr) 
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int>temp;
        int i=n%2==0?(n/2)-1:n/2, j=n-1;
        int st=i;

        while(i>=0 and j>st){
            temp.push_back(arr[i--]);
            temp.push_back(arr[j--]);
        }
        while(i>=0) temp.push_back(arr[i--]);
        while(j>st) temp.push_back(arr[j--]);

        arr=temp;
    }
};
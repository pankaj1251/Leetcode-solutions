class Solution {
public:
    void nextPermutation(string &str) 
    {
        int n=str.size();
        if(n==1)return;
        int i=n-1;
        while(i>0){
            if(str[i]>str[i-1])break;
            i--;
        }

        if(i==0){
            sort(str.begin(), str.end());
            return;
        }

        int idx = -1, j=i;
        int temp = str[i-1];

        while(j<n){
            if(str[j]<=temp)break;
            j++;
        }

        swap(str[i-1], str[j-1]); // here we want to swap the next greater element than temp.
        sort(str.begin()+i, str.end());
    }   

    int getMinSwaps(string num, int k) {
        string original = num;
        int n = num.size();

        while(k--) nextPermutation(num);  //kth permutation.
        cout<<original<<" "<<num<<endl;
        //swapping adjacent 
        int i=0, j=0;
        int ans=0;
        /*
        -as we want to calculate swapping done to change original number to kth permutation number, we do changes in our original number.
        - just find when original[j]!=num[i] and find position of num[i] in original array and do swapping to bring that element in its right place according to num string.
        */
        while(i<n){
            j=i;
            while(original[j] != num[i])j++;

            while(i<j){
                swap(original[j], original[j-1]);
                j--;
                ans++;
            }

            i++;
        }

        return ans;

    }
};
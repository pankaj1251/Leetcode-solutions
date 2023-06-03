class Solution {
public:
    int nextGreaterElement(int num) {
        string s = to_string(num);

        int n = s.size();
        int i = n-1;
        while(i>0){
            if(s[i]>s[i-1])break;
            i--;
        }

        if(i==0)return -1;
        int j=n-1;
        i--;

        while(j>i){
            if(s[j]>s[i]){swap(s[j], s[i]);break;}
            j--;
        }

        sort(s.begin()+i+1, s.end());

        long ans = stol(s);

        return ans > INT_MAX ? -1 : ans;
    }
};
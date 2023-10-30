class Solution {
public:
    static int countone(int n){
        int c=0;
        while(n){
            n=n&(n-1);
            c++;
        }
        return c;
    }

    static bool comp(int a, int b){
        int na = countone(a);
        int nb = countone(b);

        if(na==nb)return a<=b;

        return na<nb;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin(), arr.end(), comp);

        return arr;
    }
};
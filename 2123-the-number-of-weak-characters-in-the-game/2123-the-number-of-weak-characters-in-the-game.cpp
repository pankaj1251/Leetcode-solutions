//https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/solutions/2551826/c-sorting-nlogn-approach/
class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }

    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), comp);

        int maxm=INT_MIN;
        int ans=0;

        for(int i=n-1; i>=0; i--){
            if(maxm > arr[i][1]){
                ans++;
            }
            maxm = max(maxm, arr[i][1]);
        }

        return ans;
    }
};
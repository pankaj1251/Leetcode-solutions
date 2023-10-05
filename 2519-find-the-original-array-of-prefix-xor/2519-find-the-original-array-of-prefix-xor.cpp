class Solution {
public:
    vector<int> findArray(vector<int>& arr) {
        int n = arr.size();
        int pre_xor=0;

        for(int i=1; i<n; i++){
            pre_xor ^= arr[i-1];
            arr[i]=pre_xor^arr[i];
        }

        return arr;
    }
};
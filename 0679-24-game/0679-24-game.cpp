class Solution {
public:
    bool valid(vector<int>&arr){
        double a = arr[0], b = arr[1], c = arr[2], d = arr[3];

        if(valid(a+b, c, d) || valid(a-b, c, d) || valid(a*b, c, d) || valid(a/b, c, d))return true;
        if(valid(a, b+c, d) || valid(a, b-c, d) || valid(a, b*c, d) || valid(a, b/c, d))return true;
        if(valid(a, b, c+d) || valid(a, b, c-d) || valid(a, b, c*d) || valid(a, b, c/d))return true;
        
        return false;
    } 

    bool valid(double a, double b, double c){
        if(valid(a+b, c) || valid(a-b, c) || valid(a*b, c) || (b && valid(a/b, c)))return true;
        if(valid(a, b+c) || valid(a, b-c) || valid(a, b*c) || (c && valid(a, b/c)))return true;

        return false;
    }

    bool valid(double a, double b){
        if(abs(a+b-24.0)<0.001 || abs(a-b-24.0)<0.001 || abs(a*b-24.0)<0.001 || b&&abs(a/b-24.0)<0.001)return true;

        return false;
    }

    bool judgePoint24(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        do{
            if(valid(arr))return true;
        }
        while(next_permutation(arr.begin(), arr.end()));

        return false;
    }
};
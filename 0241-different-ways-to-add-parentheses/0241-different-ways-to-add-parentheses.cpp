class Solution {
public:
    int comp(int a, int b, char op){
        if(op=='+')return a+b;
        if(op=='-')return a-b;
        if(op=='*')return a*b;
        return 0;
    }

    vector<int> diffWaysToCompute(string str) {
        vector<int>ans;
        bool isNum=true;
       
        for(int i=0; i<str.length(); i++)
        {
            if(!isdigit(str[i])){
                // if current character is not a digit then
                // exp is not purely a number
                isNum=false;

                // list of first operands
                vector<int>left = diffWaysToCompute(str.substr(0, i));

                // list of second operands
                vector<int>right = diffWaysToCompute(str.substr(i+1));

                for(auto l:left){
                    for(auto r:right){
                        int val = comp(l, r, str[i]);
                        ans.push_back(val);
                    }
                }
           }
       }
        //only number is there in str.
       if(isNum==1)ans.push_back(stoi(str));

       return ans;
    }
};
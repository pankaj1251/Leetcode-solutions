class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> arr1;
        vector<string> arr2;
        
        string longest=sentence1;
        string shortest=sentence2;
        
        if(sentence1.size()<sentence2.size())
        {
            longest=sentence2;
            shortest=sentence1;
        }

        string currWord="";
        for(int i=0;i<longest.size();i++)
        {
            if(longest[i]==' ')
            {
                arr1.push_back(currWord);
                currWord="";
                continue;
            }
            currWord.push_back(longest[i]);
        }
        //add the last word too
        arr1.push_back(currWord);
        
        currWord="";
        for(int i=0;i<shortest.size();i++)
        {
            if(shortest[i]==' ')
            {
                arr2.push_back(currWord);
                currWord="";
                continue;
            }
            currWord.push_back(shortest[i]);
        }
        arr2.push_back(currWord);
        
        int start1=0;
        int start2=0;
        int end1=arr1.size()-1;
        int end2=arr2.size()-1;

         while(start1<=end1 && start2<=end2){
            if(arr1[start1]==arr2[start2])
                start1++,start2++;
            else if(arr1[end1]==arr2[end2])
                end1--,end2--;
            else
                return false;
        }
        return true;
    }
};
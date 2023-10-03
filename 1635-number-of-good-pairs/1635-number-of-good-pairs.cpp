//Program to find the number of good pairs
//Good pairs are those in which nums[i] == nums[j] and i<j
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
   
        unordered_map<int,int> umap; //Initializing a Hash Table
         
        for(int i=0;i<nums.size();i++) //Iterating through the vector
        {
            ++umap[nums[i]];  //Counting the occurences of a number and storing it in value.
            
        }
        int good_pairs = 0;
        for(auto i:umap) //Using the formula 
        {
            int n = i.second; //i.second implies -- value of hash table
            good_pairs += ((n)*(n-1))/2;
            
        }
        return good_pairs;
        
        
    }
};
    
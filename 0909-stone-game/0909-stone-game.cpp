class Solution {
public:
    int func(vector<int>& piles, int i, int j, bool turn){
        if(i>j)return 0;

        if(turn){
            int t1 = func(piles, i+1, j, false) + piles[i];
            int t2 = func(piles, i, j-1, false) + piles[j];

            return max(t1, t2);
        }

        else{
            int t1 = func(piles, i+1, j, true) - piles[i];
            int t2 = func(piles, i, j-1, true) - piles[j];

            return min(t1, t2);
        }
    }

    bool stoneGame(vector<int>& piles) {
        return(piles, 0, piles.size()-1, true);
    }
};
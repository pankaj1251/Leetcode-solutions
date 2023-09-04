#define ll long long
#define MOD 1000000007
class Solution {
public: 

    //calculates combination of selecting 'r' items among 'n' total items efficiently
    ll ncr(ll n, ll r) {
        long long p = 1, k = 1;
        if (n - r < r)
            r = n - r;
        if (r != 0) {
            while (r) {
                p *= n;
                k *= r;
                long long m = __gcd(p, k);
                p /= m;
                k /= m;
                n--;
                r--;
            }
        }
        else p = 1;
        return p;
    }
    
    //calculates the number 'n' raise to the power 'q' keeping the result less than MOD
    ll pow(ll n, ll q) {
        ll ans = n;
        while(--q) {
            ans = (ans*n)%MOD;
        }
        return ans;
    }

    int countKSubsequencesWithMaxBeauty(string s, int k) {

        // stores frequency of each character present in string
        unordered_map<char,int> freq;
        for(int i=0;i<s.length();i++) {
            freq[s[i]]++;
        }

        if(freq.size() < k) return 0;


        //stores number of characters having same frequency in decreasing order of frequency
        map<int,int, greater<int>> mp;
        for(auto [key,val]: freq) {
            mp[val]++;
        }

        ll ans = 1;

        //k characters are to be selected ,so...
        for(auto [score,freq]: mp) {
            //if number of character groups(characteres having same freq) are not more than k then make combination by selecting one character from each group
            if(freq <= k) {
                ll combination = pow(score,freq)%MOD;
                ans = (ans*combination)%MOD;
                k -= freq;
                if(!k) break;
            }
            //else take combination of character groups taking k at a time and find all combination among the selected character groups
            else {
                ll grps = ncr(freq,k)%MOD;
                ll combination = pow(score,k)%MOD;
                ans = ans*((grps*combination)%MOD)%MOD;
                break;
            }
        }
        
        return ans;
    }

};
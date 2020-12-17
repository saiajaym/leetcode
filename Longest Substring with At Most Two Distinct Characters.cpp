/*
Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.
*/


class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char,int>  a;
        set<char> ss;
        int l=0,r=0,m=-1;
        if(s.size()==0) return 0;
        
        
        while(l<s.size()){
            ss.insert(s[r]);
            if(ss.size()<3 && r<s.size()) {
                a[s[r]]++;
                m=max(m,r-l+1);
                r++;
            }else{
                a[s[l]]--;
                if( a[s[l]] == 0) ss.erase(s[l]);
                l++;
                
            }    
        }
        
        return m;
        
    }
};

/*
//simplified without set

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int mx=0,l=0,r=-1,ctr=0,n=s.size();
        map<char,int> mp;
        
        while(r<n){
            if(mp[s[++r]]++ == 0) ctr++;
            mx=max(mx,r-l);
            
            while(ctr>2){
                if(--mp[s[l++]] == 0) ctr--;
            }
        }
        return mx;
        
        
    }
};


*/

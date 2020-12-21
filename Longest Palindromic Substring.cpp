/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"

O(n^2) implementation

*/

class Solution {
public:
    int le=0,mx=1;
    string s;
    void check(int l,int r){
        while(l>=0 && r<=s.size() && s[l] == s[r]) {l--;r++;}
        l++;r--;
        if(r-l+1 > mx){
            le=l;
            mx=r-l+1;
        }
        
    }
    
    
    string longestPalindrome(string se) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        s=se;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]) check(i,i+1);
            check(i,i);
        }
        
        return s.substr(le,mx);
    }
};

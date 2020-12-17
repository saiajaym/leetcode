/*
Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".

Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Example 2:

Input: s = "a", t = "a"
Output: "a"
*/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto i : t) mp[i]++;
        int ctr=mp.size(), n=s.size();
        int l=0,r=0,mi=INT_MAX,ml=0;
        string ans="";
        
        while(r<n){
            while(ctr!=0 && r<n){
                if(--mp[s[r++]] == 0) ctr--;
            }
            
            while(l<n && ctr==0){
                if(r-l<mi) {ans=s.substr(l,r-l); mi=r-l;}
                if(++mp[s[l++]]>0) ctr++;                
            }
        }
        
        return ans;
        
    }
};

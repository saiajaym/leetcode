/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size()==0) return 0;
        int dp[100000]={0};
        haystack = needle + "$" + haystack;
        int n=haystack.size(),m=needle.size();
        
        for(int i=1,l=0,r=0; i<n;i++){
            if(r>=i) dp[i] = min(dp[i-l], r-i+1);
            while(i+dp[i]<n && haystack[dp[i]] == haystack[dp[i]+i]) dp[i]++;
            if(dp[i]+i>r){r=dp[i]+i-1;l=i;}
            if(dp[i]==m) return i-needle.size()-1;
        }
        return -1;        
        
    }
};

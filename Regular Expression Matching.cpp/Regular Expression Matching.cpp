/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
*/

class Solution {
public:
    int m,n;
      //i,j
    int dp[21][31]={{-1}};
    string str, pat;
    bool rec(int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(j>=n) return dp[i][j]= (i==m);
        
        if(pat[j+1] == '*') {
            dp[i][j] = rec(i, j+2);
            if(pat[j]=='.' || pat[j]==str[i]) return  dp[i][j] = (dp[i][j] || (i<m && rec(i+1, j)));
        }
        else return dp[i][j] = (i<m && (pat[j]==str[i]|| pat[j]=='.') && rec(i+1,j+1));
        return dp[i][j];
    }
    
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        m=s.size(),n=p.size();
        str=s,pat=p;
        return rec(0,0);
    }
};

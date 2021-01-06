/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
*/

class Solution {
public:
    string str,pat;
    int m,n;
      //i,j
    vector<vector<int>> dp;
    bool rec(int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        if(j>=n) return dp[i][j] = (i==m);
        
        if(pat[j] == '*') return dp[i][j] = (rec(i,j+1) || (i<m && rec(i+1,j)));
        if(pat[j] == '?' || str[i] == pat[j] ) return dp[i][j] = (i<m && rec(i+1,j+1));
        return dp[i][j]=false;
    }

//recursive approach -  bottom up dp -O(n^2)
/* 

    bool isMatch(string s, string p) {
        str=s, pat=p,m=s.size(), n=p.size();
        vector<vector<int>> tmp(s.size()+1, vector<int>(p.size()+1,-1));
        dp=tmp;
        return rec(0,0);        
    }
*/
    
//linear greedy approach - O(nm)


// greedy solution with idea of DFS
// starj stores the position of last * in p
// last_match stores the position of the previous matched char in s after a *
// e.g. 
// s: a c d s c d
// p: * c d
// after the first match of the *, starj = 0 and last_match = 1
// when we come to i = 3 and j = 3, we know that the previous match of * is actually wrong, 
// (the first branch of DFS we take is wrong)
// then it resets j = starj + 1 
// since we already know i = last_match will give us the wrong answer
// so this time i = last_match+1 and we try to find a longer match of *
// then after another match we have starj = 0 and last_match = 4, which is the right solution
// since we don't know where the right match for * ends, we need to take a guess (one branch in DFS), 
// and store the information(starj and last_match) so we can always backup to the last correct place and take another guess.


        bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int m = s.length(), n = p.length();
        int last_match = -1, starj = -1;
        while (i < m){
            if (j < n && (s[i] == p[j] || p[j] == '?')){
                i++; j++;
            }
            else if (j < n && p[j] == '*'){
                starj = j;
                j++;
                last_match = i;
            }
            else if (starj != -1){
                j = starj + 1;
                last_match++;
                i = last_match;
            }
            else return false;
        }
        while (p[j] == '*' && j <n) j++;
        return j == n;
    }
};

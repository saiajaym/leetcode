/*
Given a string s, you can convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

 

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
*/

class Solution {
public:
string shortestPalindrome(string se) {
        int n=se.size(), mx=-1,mi=-1;
        int dp[100000]={0};
		//preprocess
        string s="*#";
        for(int i=0;i<n;i++) s.push_back(se[i]), s.push_back('#');
        s+="&";
        int c=0,r=0;
		//manchers algorithm
        for(int i=0;i<s.size();i++){
            int mirror= c-(i-c);
            if(r>i)
                dp[i] = min(dp[mirror], r-i);
            while(i+dp[i]<=s.size() && i-dp[i]>=0 && s[i-dp[i]]==s[i+dp[i]]) dp[i]++;
            if(i+dp[i]>r){r =i+dp[i]; c=i;}
            if((i-dp[i] == 0 || i-dp[i]==1)  && dp[i]>mx){
                mx= ((dp[i]%2==0)?dp[i]/2: dp[i]/2+1);
                mi= (i)/2-1; 
            }
            
        }
        //reverse the remaining string and append to original
        string res = se.substr(mi+mx);
        reverse(res.begin(),res.end());
        return res+se;
    }
};

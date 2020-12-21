class Solution {
public:
    string longestPalindrome(string se) {
        string s="*#";
        //preprocess
        for(int i=0;i<se.size();i++) s.push_back(se[i]),s.push_back('#');
        s+="$";
        int c=0,r=0, dp[20000]={0};
        
        //idea is utilize the computed palindromes
        for(int i=0;i<s.size();i++){
            int miror = c-abs(i-c);
            if(r>i) dp[i] = min(dp[miror], r-i);
            while(i-dp[i]>=0 && i+dp[i]<s.size() && s[i-dp[i]]==s[i+dp[i]]) dp[i]++;
            if(dp[i]+i>r){
                r=dp[i]+i;
                c=i;
            }
        }
        int mx=-1,mi=-1;
        for(int i=0;i<s.size();i++){
            if(dp[i]>mx){
                mx=dp[i]; 
                mi=i;
            }
        }
        mx=mx-1;
        string ans = s.substr(mi-mx, mx*2+1);
        string a;
        for(int i=0;i<ans.size();i++) if(!(ans[i]=='#')) a.push_back(ans[i]);
        
        return a; 
        
    }
};

/*
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
*/

/*
//Uses two pointers sliding window

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>  a;
        int l=0,r=0,m=-1;
        if(s.size()==0) return 0;
        while(l<s.size()){
            if(a[s[r]]+1 < 2 && r<s.size()) {
                a[s[r]]++;
                m=max(m,r-l+1);
                r++;
            }else{
                a[s[l]]--;
                l++;
            }
            
            
        }
        
        return m;
        
    }
};


*/

class Solution {
public:
   int lengthOfLongestSubstring(string s) {
        vector<int> dict(128, -1);
        int start=-1, mx=0;
       for(int i=0;i<s.size();i++){
           if(dict[s[i]]>start) start = dict[s[i]];
           dict[s[i]] = i;
           mx = max(mx,i-start);
       }
       return mx;
    }
};

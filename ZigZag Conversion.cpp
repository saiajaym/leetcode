/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

*/



class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> sol(numRows);
        int tog,i=0;
        numRows-=1;
        while(i<s.size()){
            tog=numRows;
            while(i<s.size() && tog>=0){sol[numRows-(tog--)].push_back(s[i++]);}
            tog=numRows-1;
            while(i<s.size() && tog>=1){sol[tog--].push_back(s[i++]);}
        }
        
        string ans;
        for(auto i :sol) ans+=i;
        return ans;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
         vector<vector<char>> mt(numRows, vector<char>(s.length(), '-'));
        int p=0;
        int j=0;
while(p<s.length()){  
     for(int i=0;i<numRows && p < s.length();i++,p++){
        mt[i][j]=s[p];
     }
     j++;
     for(int i=numRows-2;i>0&& p < s.length();i--,j++,p++){
        mt[i][j]=s[p];
     }
}
string temp="";
for(int i=0;i<numRows;i++){
    for(int j=0;j<s.length();j++){
        if(mt[i][j]!='-'){ temp=temp+mt[i][j];}
    }
}
return temp;
    }

};
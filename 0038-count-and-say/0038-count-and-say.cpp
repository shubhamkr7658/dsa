class Solution {
public:
    string countAndSay(int n) {
        string temp="1";
        for(int i=2;i<=n;i++){
            string t="";
            int p=0; 
            int j=0;
            int t1=0;
            while(j<temp.size()){
            if(temp[j]==temp[p]){
            t1++;
            }
            else{
               t=t+to_string(t1)+temp[p];
               p=j;
               t1=1;

            }
            j++;
            }
            t=t+to_string(t1)+temp[p];
            temp=t;
        }
        return temp;
    }
};
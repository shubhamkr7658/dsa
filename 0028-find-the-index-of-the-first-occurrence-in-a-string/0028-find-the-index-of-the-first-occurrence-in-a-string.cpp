class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
        int j=0;
        int n1=haystack.size();
        int n2=needle.size();
        int count=0;
        int last=-1;
        while(i<n1 && j<n2){
            last=i;
            while(i<n1 && j<n2 && haystack[i]==needle[j]){
                count++;
                i++;
                j++;
                continue;
            }
            if(count==n2){
                break;
            }
            count=0;
            i=last;
            j=0;
            i++;
            
        }
        if(count==n2){
            return i-n2;
        }
        return -1;
    }
};
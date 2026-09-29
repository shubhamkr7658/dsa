class Solution {
public:
typedef long long ll;
    int minDays(vector<int>& bloom, int m, int k) {
        int maxi=bloom[0];
        if(bloom.size()<((1ll*m)*k)){
            return -1;
        }
        for(int i=1;i<bloom.size();i++){
            maxi=max(bloom[i],maxi);
        }
        int a=1;
        while(maxi>=a){
            int mid=a+(maxi-a)/2;
            int count=0;
            int temp=0;
            for(int i=0;i<bloom.size();i++){
             if(bloom[i]<=mid){
                temp++;
             if(temp==k){
                count++;
                temp=0;
             }
             }
             else{
                temp=0;
             }
            }
            if(count>=m){
                maxi=mid-1;
            }
            else{
                a=mid+1;
            }
        }
        return a;
    }
};
class Solution {
public:
typedef long long ll;
    int shipWithinDays(vector<int>& we, int days) {
        ll max=we[0];
        int min=we[0];
        for(int i=1;i<we.size();i++){
            if(min<we[i]){
                min=we[i];
            }
          max+=we[i];
        }
        while(max>=min){
            ll mid=min+(max-min)/2;
            ll sum=0;
            int day=1;
            for(int i=0;i<we.size();i++){
                if(sum+we[i]>mid){
                   day++;
                    sum=0;
                }
                sum+=we[i];
            }
            if(day<=days){
                max=mid-1;
            }
            else{
                min=mid+1;
            }
        }
        return min;
    }
};
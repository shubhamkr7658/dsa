class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
       int m=1e9+7;
       int n=arr.size();
       int odd=0;
       int even=1;
       int sum=0;
       int ans=0;
       for(int i=0;i<n;i++){
         sum+=arr[i];
         if(sum%2==0){
        ans=(ans+odd)%m;
        even++;
         }
         else{
            ans=(ans+even)%m;
            odd++;
         }
       } 
       return ans;
    }
};
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>lsm(n,-1);
        vector<int>rsm(n,n);
        vector<int>lmx(n,-1);
        vector<int>rmx(n,n);
        stack<int>smin;
        stack<int>smax;
        for(int i=0;i<n;i++){
        while(!(smin.empty())&&nums[i]>=nums[smin.top()]){
            smin.pop();
        }
        if(!(smin.empty())){
            lsm[i]=smin.top();
        }else{
            lsm[i]=-1;
        }
        smin.push(i);
         while(!(smax.empty())&&nums[i]<=nums[smax.top()]){
            smax.pop();
        }
        if(!(smax.empty())){
            lmx[i]=smax.top();
        }else{
            lmx[i]=-1;
        }
        smax.push(i);

        }
        while(!smax.empty()){
            smax.pop();
        }
        while(!(smin.empty())){
            smin.pop();
        }
        for(int i=n-1;i>=0;i--){
        while(!(smin.empty())&&nums[i]>nums[smin.top()]){
            smin.pop();
        }
        if(!(smin.empty())){
            rsm[i]=smin.top();
        }else{
            rsm[i]=n;
        }
        smin.push(i);
         while(!(smax.empty())&&nums[i]<nums[smax.top()]){
            smax.pop();
        }
        if(!(smax.empty())){
            rmx[i]=smax.top();
        }else{
            rmx[i]=n;
        }
        smax.push(i);

        }
        long long summin=0;
        long long summax=0;
        for(int i=0;i<n;i++){
         long long temp=1ll*(i-lsm[i])*(rsm[i]-i)*nums[i];
         summin+=temp;
         temp=1ll*(i-lmx[i])*(rmx[i]-i)*nums[i];
         summax+=temp;
        }
        return(-(summax-summin));
    }
};
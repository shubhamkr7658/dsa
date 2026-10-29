class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        priority_queue<int>maxpq;
  long long ans=0;
  
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[i]=-nums[i];
            }
        }
        for(int i=0;i<n;i++){
            maxpq.push(nums[i]);
        }
        if(n%2==1){
            for(int i=0;i<(n/2+1);i++){
                int t=maxpq.top();
                ans+=t*t;
                maxpq.pop();
            }
            for(int i=(n/2+1);i<n;i++){
                int t=maxpq.top();
                ans-=t*t;
                maxpq.pop();
            }
        }
        else{
            for(int i=0;i<n/2;i++){
                int t=maxpq.top();
                ans+=t*t;
                maxpq.pop();
            }
            for(int i=n/2;i<n;i++){
                int t=maxpq.top();
                ans-=t*t;
                maxpq.pop();
            }
        } 
        return ans;      
    }
};
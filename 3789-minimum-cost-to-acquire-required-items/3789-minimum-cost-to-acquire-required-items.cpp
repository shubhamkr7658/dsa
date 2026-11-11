class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int c1=min(cost1+cost2,costBoth);
        int n=min(need1,need2);
        long long ans=1LL*c1*n;
        ans+=1LL*(need1-n)*min(cost1,c1)+1LL*(need2-n)*min(cost2,c1);
        return ans;
    }
};
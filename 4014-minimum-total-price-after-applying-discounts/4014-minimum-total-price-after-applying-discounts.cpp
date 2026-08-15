class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());
        int i,j=0;
        double sum=0;
        for( i=0;i<prices.size();i++,j++){
         if(j<discounts.size()){
         sum+=(prices[i]*double(100-discounts[j])/100);
         }
         else{
         sum+=prices[i];
         }
        }
        return sum;
    }
};
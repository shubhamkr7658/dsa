class Solution {
public:
unordered_map<int,int>map;
    int largestInteger(vector<int>& nums, int k) {
        int i=0;
        int j=k-1;
        for(int i=0;i<k;i++){
            map[nums[i]]=1;
        }
        while(j<nums.size()-1){
             j++;
             i++;
            for(int t=i;t<=j;t++){  
             if(map[nums[t]]==0)
             map[nums[t]]++;
             else{
             map[nums[t]]=12;
             }
            }
            
        }

        int maxi=-1;
        for(int p=0;p<51;p++){
            if(map.find(p)!=map.end()&& map[p]==1 && maxi<p){
                    maxi=p;
            }
        }
        if(maxi==-1){
            return -1;
        }
        return maxi;
    }
};
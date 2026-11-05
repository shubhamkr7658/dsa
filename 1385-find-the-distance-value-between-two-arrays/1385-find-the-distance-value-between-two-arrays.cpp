class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr1.size();
        int count=0;
        int j=0;
        for(int i=0;i<n;i++){
            for(j=0;j<arr2.size();j++){
                if(abs(arr1[i]-arr2[j])>d){
                    continue;
                }
                else{
                    break;
                }
            }
            if(j==arr2.size())
            count++;
        }
        return count;
    }
};
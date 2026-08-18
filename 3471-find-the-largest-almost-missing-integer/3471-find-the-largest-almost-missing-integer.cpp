class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }        
        int x=-1;
        for(int j=0;j<nums.size();j++){
            if(k==1){
                if(mp[nums[j]]==1){
                    x=max(nums[j],x);
                }
            }
            else if(k==n){
                x=max(nums[j],x);
            }
            else{
                if(j==0 && mp[nums[j]]==1){
                    x=max(nums[j],x);
                }
                if(j==n-1 && mp[nums[j]]==1){
                    x=max(nums[j],x);
                }
            }
        }
 
        return x;
    }
};
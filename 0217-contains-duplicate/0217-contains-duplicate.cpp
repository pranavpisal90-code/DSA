class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
  
      for(auto [key,count]:mp){
            if(count>=2){
                return true;
            }
        }
        return false;

    }
};
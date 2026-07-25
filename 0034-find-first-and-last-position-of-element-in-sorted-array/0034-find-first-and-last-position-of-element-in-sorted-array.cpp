class Solution {
public:
    int last1(vector<int>& nums,int target){
       int last=-1;
        int low=0;
        int high=nums.size()-1;

        int mid;
        while(low<=high){

            mid=(low+high)/2;

            if(nums[mid]==target){
               low=mid+1;
               last=mid;

            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }


        }
        return last;

    }
     int first1(vector<int>& nums,int target){
       int first=-1;
       
        int low=0;
        int high=nums.size()-1;
        int mid;
        while(low<=high){

            mid=(low+high)/2;

            if(nums[mid]==target){
                high=mid-1;
                first=mid;

            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }


        }

      return first;
      
    }
    


    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v1;
        int f=first1(nums,target);
         int l=last1(nums,target);
        v1.push_back(f);
        v1.push_back(l);
        return v1;
    }
};
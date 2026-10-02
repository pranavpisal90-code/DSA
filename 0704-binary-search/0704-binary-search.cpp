class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left;
        int right;
        int mid;
        int index=-1;

        left=0;
        right=nums.size()-1;

        while(left<=right){
            mid=left + (right-left)/2; //to prevent inetegr overflow
            if(target < nums[mid]){
                right=mid-1;
            }
            else if(target > nums[mid]){
                left=mid+1;
            }
            else{
                index=mid;
                return index;
            }

        }
        return index;

    }
};

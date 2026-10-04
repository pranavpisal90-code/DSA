class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // 1. Check if the left half is sorted
            if (nums[l] <= nums[mid]) {
                // Check if target lies within the sorted left half
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1; // Target is in left half
                } else {
                    l = mid + 1; // Target is in right half
                }
            } 
            // 2. Otherwise, the right half MUST be sorted
            else {
                // Check if target lies within the sorted right half
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1; // Target is in right half
                } else {
                    r = mid - 1; // Target is in left half
                }
            }
        }

        return -1; // Target not found
    }
};
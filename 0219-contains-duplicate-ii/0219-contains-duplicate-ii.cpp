class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastSeen;
        
        for (int i = 0; i < nums.size(); i++) {
            int currentNum = nums[i];
            
           
            if (lastSeen.count(currentNum)) {
                // 2. Check if it's within distance k
                if (i - lastSeen[currentNum] <= k) {
                    return true;
                }
            }
           
            lastSeen[currentNum] = i;
        }
        
        return false;
    }
};
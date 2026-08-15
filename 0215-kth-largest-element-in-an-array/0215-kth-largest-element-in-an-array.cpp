class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        for(int j=pq.size()-1;j>k-1;j--){
            pq.pop();
        }
        return pq.top();
    }
};
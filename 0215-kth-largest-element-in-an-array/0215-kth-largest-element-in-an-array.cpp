class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>> q1;

        for(auto c:nums){
            q1.push(c);
        }

        int i=0;
        while(i<k-1){
            q1.pop();
            i++;
        }
        return q1.top();
    }
};
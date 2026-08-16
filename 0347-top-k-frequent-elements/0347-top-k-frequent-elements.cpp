class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> x;

        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int,int>> q;
        for(auto [key,count]:mp){
            q.push({count,key});
        }
       
       while (!q.empty() && k > 0) {
            auto [count, key] = q.top(); 
            q.pop();                    
            
            x.push_back(key);           
            k--;
        }
        
        return x;


    }
};
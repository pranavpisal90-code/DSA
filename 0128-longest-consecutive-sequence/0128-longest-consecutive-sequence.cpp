class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s1(nums.begin(),nums.end());
int max_=0;
int y;
int x;
int count=0;
        for(const auto& x:s1){
           
            if(!s1.contains(x-1)){
                y=x+1;
                while(s1.contains(y)){
                    count++;
                    y=y+1;
                }          

            }
            max_=max(count,max_);
            count=0;
        }
        if(nums.empty()){
            return 0;
        }
         return max_+1;

    }
};

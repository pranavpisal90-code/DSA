class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul=1;
        int n=nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> output(n);
        for(int i=0;i<nums.size();i++){
            mul=nums[i]*mul;
            prefix[i]=mul;
        }
        mul=1;
        for(int j=n-1;j>=0;j--){
            mul=nums[j]*mul;
            suffix[j]=mul;
        }

        for (int x = 0; x < n; x++) {
            int left = 1;
            int right = 1;

            if (x > 0) {
                left = prefix[x - 1];
            }

            if (x < n - 1) {
                right = suffix[x + 1];
            }

            output[x] = left * right;
        }


        return output;
    }
};

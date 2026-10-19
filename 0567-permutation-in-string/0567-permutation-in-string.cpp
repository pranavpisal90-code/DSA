class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> count1,count2;
        int n1=s1.length();
        int n2=s2.length();
        if(n1>n2) return false;

        for(int i=0;i<s1.length();i++){
            count1[s1[i]]++;
            count2[s2[i]]++;
        }

        if(count1==count2) return true;

        for(int i=n1;i<s2.length();i++){
            char incoming=s2[i];
            char out_going=s2[i-n1];

            count2[incoming]++;
            count2[out_going]--;

            if(count2[out_going]==0){
                count2.erase(out_going);
            }

            if(count1==count2){
                return true;
            }
        }
        return false;
    }
};

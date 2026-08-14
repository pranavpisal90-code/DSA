class Solution {
public:
    void reverseString(vector<char>& s) {

        if(s.size()>=2){
        int temp;
        int j=s.size()-1;
        for(int i=0;i<s.size();i++){
            if(j>i){
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            j--;
            }
         }
        }

    }
};
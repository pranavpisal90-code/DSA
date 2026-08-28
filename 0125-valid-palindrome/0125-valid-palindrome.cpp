class Solution {
public:
    bool isPalindrome(string s) {
        int j=s.length()-1;
        int i=0;
        bool x=true;
      
        while(i<s.length()){
         if(j>=i){
            while(i<j && !isalnum(s[i])){
                i++;
            }
            while(j>i && !isalnum(s[j])){
                j--;
            }
            

                if(tolower(s[i])!=tolower(s[j])){
                    return false;
                }
           
             j--;
             i++;
            }
          else{
                break;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {

        map<char,int> mp1;
        for(int i=0;i<s.length();i++){
            mp1[s[i]]++;
        }
        map<char,int> mp2;
        for(int j=0;j<t.length();j++){
            mp2[t[j]]++;
        }
        if(s.length()==t.length()){
        for(int x=0;x<s.length();x++){

            if(mp1[s[x]]!=mp2[s[x]]){
                return false;
            }
        }
        return true;
    }
    
    return false;
    }
};

#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> seen;
        int l = 0;
        int max_len = 0;

        for (int r = 0; r < s.length(); r++) {
            // If duplicate found, shrink window from the left
            while (seen.count(s[r])) {
                seen.erase(s[l]);
                l++;
            }
            
            // Add current character and track max window length
            seen.insert(s[r]);
            max_len = std::max(max_len, r - l + 1);
        }

        return max_len;
    }
};
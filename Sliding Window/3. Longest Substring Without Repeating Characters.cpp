#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.length();
        if(n==0)
        return 0;
        unordered_map<char, int> freq;
        int i = 0;
        int j = 0;
        int len = 0;
        int maxLen = INT_MIN;
        while (j < n) {

            // collapse the window when conditions fails
            while (freq[str[j]] == 1) {
                len -= 1;
                freq[str[i]]--;
                i++;
            }
            // currrent character ko include kiya
            len += 1;
            freq[str[j]]++;
            maxLen = max(maxLen, len);
            j++;
        }
        return maxLen;
    }
};
int main() {
    Solution sol;
    string str = "abcabcbb";
    int result = sol.lengthOfLongestSubstring(str);
    cout << "Length of Longest Substring Without Repeating Characters: " << result << endl; // Output: 3
    return 0;
}
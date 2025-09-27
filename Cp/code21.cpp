#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    string majorityFrequencyGroup(string str) {
        int n = str.length();
        unordered_map<char, int> mp;

        for (auto ele : str) {
            mp[ele]++;
        }

        vector<unordered_set<char>> arr(n + 1);
        for (auto &ele : mp) {
            arr[ele.second].insert(ele.first);
        }

        unordered_set<char> ans;
        int sz = INT_MIN;

        for (auto &ele : arr) {
            if (ele.empty()) continue;
            int size = ele.size();
            if (sz < size) {
                ans = ele;
                sz = size;
            } else if (sz == size) {
                if (mp[*ele.begin()] > mp[*ans.begin()]) {
                    ans = ele;
                }
            }
        }
        string result = "";
        for (auto ch : ans) {
            result += ch;
        }
        return result;
    }
};
int main(){
    
}
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.length();
        vector<int> prefixX(n + 1, 0);
        vector<int> prefixY(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixX[i + 1] = prefixX[i];
            prefixY[i + 1] = prefixY[i];
            if (s[i] == 'U') 
            prefixY[i + 1]++;
            else if (s[i] == 'D') 
            prefixY[i + 1]--;
            else if (s[i] == 'L') 
            prefixX[i + 1]--;
            else if (s[i] == 'R') 
            prefixX[i + 1]++;
        }
        vector<int> suffixX(n + 1, 0);
        vector<int> suffixY(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffixX[i] = suffixX[i + 1];
            suffixY[i] = suffixY[i + 1];
            if (s[i] == 'U') 
            suffixY[i]++;
            else if (s[i] == 'D') 
            suffixY[i]--;
            else if (s[i] == 'L') 
            suffixX[i]--;
            else if (s[i] == 'R') 
            suffixX[i]++;
        }

        set<pair<int, int>> st;

        for (int i = 0; i <= n - k; ++i) {
           
            int pdx = prefixX[i];
            int pdy = prefixY[i];
            
            int sdx = suffixX[i + k];
            int sdy = suffixY[i + k];

            st.insert({pdx + sdx, pdy + sdy});
        }

        return st.size();
    }
};
int main(){

}
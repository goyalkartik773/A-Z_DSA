#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool customcomparator(vector<int>& a, vector<int>& b) {
    // sort on the basis of no of units
    return a[1] > b[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& arr, int Size) {
        sort(arr.begin(), arr.end(),customcomparator);
        int ans = 0;
        for (auto ele : arr) {
            int boxes = ele[0];
            int units = ele[1];
            if (Size < boxes) {
                ans = ans + Size * units;
                break;
            } else {
                ans = ans + boxes * units;
                Size = Size - boxes;
            }
        }
        return ans;
    }
};
int main(){
    
}
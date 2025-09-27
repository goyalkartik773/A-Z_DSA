#include <isotream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq; //{key,frequency}
        int i = 0;
        int j = 0;
        int sum = 0;
        int maxSum = INT_MIN;
        while (j < n) {
            // collapse the window when uniqueness fails
            while (freq[arr[j]] == 1) {
                sum -= arr[i];
                freq[arr[i]]--;
                i++;
            }
            sum += arr[j];
            freq[arr[j]]++;
            maxSum = max(maxSum, sum);
            j++;
        }
        return maxSum;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {4, 2, 4, 5, 6};
    int result = sol.maximumUniqueSubarray(arr);
    cout << "Maximum Unique Subarray Sum: " << result << endl; // Output: 17
    return 0;
}
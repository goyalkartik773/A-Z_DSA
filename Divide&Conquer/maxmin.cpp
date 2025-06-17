#include <iostream>
#include <vector>
using namespace std;

// Structure to hold min and max
struct MinMax {
    int min;
    int max;
};

MinMax findMinMax(const vector<int>& arr, int low, int high) {
    MinMax result, left, right;

    // If there's only one element
    if (low == high) {
        result.min = result.max = arr[low];
        return result;
    }

    // If there are two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // If more than two elements
    int mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    result.min = min(left.min, right.min);
    result.max = max(left.max, right.max);

    return result;
}

int main() {
    vector<int> arr = {5, 3, 8, 6, 2, 10, 4};
    int n = arr.size();

    MinMax result = findMinMax(arr, 0, n - 1);

    cout << "Minimum element: " << result.min << endl;
    cout << "Maximum element: " << result.max << endl;

    return 0;
}

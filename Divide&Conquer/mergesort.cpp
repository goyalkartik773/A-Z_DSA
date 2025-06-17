#include <iostream>
#include <vector>

using namespace std;

// Merge two sorted subarrays
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left;      // Start of left subarray
    int j = mid + 1;   // Start of right subarray

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    // Copy remaining elements (if any)
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    // Copy sorted elements back into original array
    for (int k = left; k <= right; k++)
        arr[k] = temp[k - left];
}

// Recursive merge sort function (Divide & Conquer)
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return; // Base case

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);        // Sort left half
    mergeSort(arr, mid + 1, right);   // Sort right half
    merge(arr, left, mid, right);     // Merge both halves
}

// Driver code
int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original array:\n";
    for (int x : arr) cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array:\n";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

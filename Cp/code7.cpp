#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> arr = {3, 4, 5, 1, 2};
  int left = 0;
  int right = arr.size() - 1;
  int pkIdx = -1;
  // o(logn approach to find minimum element just carefully observe the
  // array if you see its mountain then just do binary search)
  while (left <= right) {
    int mid = (left + right) / 2;
    if ((mid == 0 || arr[mid] > arr[mid - 1]) &&
        (mid == arr.size() - 1 || arr[mid] > arr[mid + 1])) {
      pkIdx = mid;
      break;
    } else if (arr[mid] < arr[right])
      right = mid;
    else // arr[mid] < arr[mid-1]
      left = mid + 1;
  }

  if (pkIdx != arr.size() - 1)
    cout << arr[pkIdx + 1];
  else
    cout << arr[0];
}
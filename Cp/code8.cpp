#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> arr = {4,5,6,7};
    int n = arr.size();
    int left = 0;
    int right = n - 1;
    int target = 6;
    bool flag = false;
    while(left <= right){
        int mid = (left + right)/2;

        if(arr[mid]==target){
            flag = true;
            cout<<mid<<" ";
            break;
        }
        else if(arr[mid] < arr[right]){
            // array is sorted from mid to right
            if(target > arr[mid] && target <= arr[right]){
                left = mid +1;
            }
            else{
                right = mid - 1;
            }
        }
        else{
            // array is sorted from mid to left
            if(target < arr[mid] && target >= arr[left]){
               right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
    }
    if(!flag)
    cout<<-1;

}
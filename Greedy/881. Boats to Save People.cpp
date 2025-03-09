#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int numRescueBoats(vector<int>& arr, int limit) {
    // will solve using greedy approach uss pair of person ko pick karega jiska weight within limit hoga 
    // use two pointer 
    sort(arr.begin(),arr.end());
    int i = 0; 
    int j = arr.size()-1;
    int count = 0;
    while(i < j){
        if(arr[i] + arr[j] <= limit)
        {
            count++;
            i++,j--;
        }
        else if(arr[i] == limit && arr[i] + arr[j] > limit){
            count++;
            i++;
        }
        else if(arr[j] == limit && arr[i] + arr[j] > limit){
            count++;
            j--;
        }
    }
    return count;
}
int main(){
vector<int> arr = {1,1,2,3};
cout<<numRescueBoats(arr,4);
}
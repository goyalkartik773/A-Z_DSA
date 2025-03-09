#include <iostream>
#include <vector>
using namespace std;
int find_minimum(vector<int> &arr)
{
    int min = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}
int minimum_product(vector<int> &arr)
{
    int n = arr.size();
    int cp = 0;
    int cn = 0;
    int cz = 0;
    int posprod = 1;
    int negprod = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            cz++;
        else if (arr[i] < 0)
        {
            cn++;
            negprod *= arr[i];
        }
        else
        {
            cp++;
            posprod = posprod * arr[i];
        }
    }
    if (cn == 0)
    {
        // only positive number
        if (cz == 0)
        {
            // minmium element would be the minimum subset
            return find_minimum(arr);
        }
        else
            return 0;
    }
    else
    {
        if (cn % 2 == 0)
        {
            // negative number even times present hai
            int smallest = find_minimum(arr);
            return posprod * smallest;
        }
        else
        {
            return posprod * negprod;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = { -1, 0  };
    cout<<minimum_product(arr);
}
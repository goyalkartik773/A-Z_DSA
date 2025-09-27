#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        long long countZeros = 0;
        long long countNeg = 0;
        int maxEle = INT_MIN;
        long long result = 0;
        for(int i=0; i<n; i++)
        {
            if(arr[i]==0)
            {
                countZeros++;
            }
            else if(arr[i]<0)
            {
                countNeg++;
                maxEle = max(maxEle,arr[i]);
            }
        }
        result += countZeros;
        if(countNeg%2!=0)
        {
            result+= abs(maxEle) + 1;

        }
        cout<<result<<endl;
    }
}


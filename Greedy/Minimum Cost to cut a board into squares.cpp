#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;
bool customcomparator(int a, int b){
    return a>b;
}
int minimumCostOfBreaking(vector<int> x, vector<int> y, int M, int N)
{
    // sorted costs in decreasing order
    sort(x.begin(), x.end(), customcomparator);
    sort(y.begin(), y.end(), customcomparator);
    int i = 0;
    int j = 0;
    int hbox = 1;
    int vbox = 1;
    int cost = 0;
    while (i < x.size() && j < y.size())
    {
        if (x[i] >= y[j])
        {
            // verical box ko cut karne ka cost jada hai
            cost = cost + x[i] * hbox;
            vbox = vbox + 1;
            i++;
        }
        else
        {
            // horizontal box ko cut karne ki cost jada hai
            cost = cost + y[j] * vbox;
            hbox = hbox + 1;
            j++;
        }
    }
    if (i == x.size() && j != y.size())
    {
        while (j < y.size())
        {
            cost = cost + y[j] * vbox;
            hbox = hbox + 1;
            j++;
        }
    }
    if (j == y.size() && i != x.size())
    {
        while (i < x.size())
        {
            cost = cost + x[i] * hbox;
            vbox = vbox + 1;
            i++;
        }
    }
    return cost;
}
int main()
{
}
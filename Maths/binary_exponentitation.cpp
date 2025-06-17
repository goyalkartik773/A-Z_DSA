#include <iostream>
using namespace std;
int find_power(int n, int m)
{
    if (m == 0)
        return 1; // base case
    if (m % 2 == 0)
    {
        int half_power = find_power(n, m / 2);
        return half_power * half_power; // even exponent
    }
    else
    return n * find_power(n, m - 1); // odd exponent
}
int main()
{
    int n, m;
    cout << "Enter the base and exponent: ";
    cin >> n >> m;
    cout<<find_power(n, m) << endl; // output the result

    return 0;
}
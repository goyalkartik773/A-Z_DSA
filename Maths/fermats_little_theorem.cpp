#include<iostream>
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
    // this theorem use to find the modular inverse of a number i.e a^(p-2) mod p here p is a prime number 
    int a,b,p;
    cin>>a>>b>>p;
    // Fermat's little theorem states that if p is a prime number and a is an integer not divisible by p, then a^(p-1) ≡ 1 (mod p).
    int result = a*find_power(b,p-2);
    result = result % p; // taking modulo p
    cout << "The modular inverse of " << a << " under modulo " << p << " is: " << result << endl;
    return 0;
}
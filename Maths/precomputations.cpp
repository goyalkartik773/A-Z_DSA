#include <iostream>
using namespace std;
#define mod 1000000007
const int MAX = 1e6 + 5; // Should be >= max n you expect
long long fact[MAX], inv_fact[MAX];

// Precompute factorials and inverse factorials
void precompute_factorials()
{
    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = (fact[i - 1] * i) % mod;

    // Using Fermat's Little Theorem: a^(mod - 2) ≡ a⁻¹ mod mod
    inv_fact[MAX - 1] = power(fact[MAX - 1], mod - 2);
    for (int i = MAX - 2; i >= 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
}

long long power(long long a, long long b)
{
    long long res = 1;
    a %= mod;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// Now you can get nCr in O(1)
long long nCr(int n, int r)
{
    if (r > n || r < 0)
        return 0;
    return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

int main()
{

    return 0;
}
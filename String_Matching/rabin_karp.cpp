#include <iostream>
#include <math.h>
using namespace std;
int hash_value(string needle, int base, int m)
{
    int hashval = 0;
    for (int i = 0; i < m; i++)
    {
        hashval = hashval + (needle[i] - 'a') * pow(base, m - i - 1);
    }
    return hashval;
}
int rabin_karp_idx(string text, string pattern, int base)
{
    int n = text.length();
    int m = pattern.length();
    // step-1 --> find the hash value of the pattern string
    int pval = hash_value(pattern, base, m);
    int hval = 0;
    // step-2 --> using sliding window match hashvalue of all substring of text with pattern hash value
    for (int i = 0; i < n - m + 1; i++)
    {
        if (i == 0)
        {
            // for first time iterate upto m to calculate hashvalue done only once
            hval = hash_value(text, base, m);
        }
        else
        {
            // for other idxs make update in previous hash only
            hval = (hval - (text[i - 1] - 'a') * pow(base, m - 1)) * base + (text[m + i - 1] - 'a');
        }
        if (hval == pval)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    string text = "abbcaaca";
    string pattern = "aca";
    cout <<"pattern matched to text\n"<<"starting idx in text is : " <<rabin_karp_idx(text, pattern, 10);
}
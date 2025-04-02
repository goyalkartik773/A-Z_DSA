#include <iostream>
#include <vector>
using namespace std;
int naive_approach(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    for (int i = 0; i < n - m + 1; i++)
    {
        bool flag = false;
        int idx = i;
        for (int j = 0; j < m; j++)
        {
            if (pattern[j] != text[idx])
            {
                flag = false;
                break;
            }
            else
            {
                idx++;
                flag = true;
            }
        }
        if (flag == true)
        {
            cout << "pattern is matched to text\n";
            return i;
        }
    }
    return -1;
}
int main()
{
    string text = "ababcabcabababd";
    string pattern = "ababd";
    // t.c --> o(m*n);
    cout<<naive_approach(text,pattern);
}
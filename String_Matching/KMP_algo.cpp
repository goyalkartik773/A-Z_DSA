#include <iostream>
#include <vector>
using namespace std;
vector<int> lps_table(string pattern)
{
    int n = pattern.length();
    int pre = 0;
    int suff = 1;
    vector<int> lps(n, 0);
    while (suff < n)
    {
        if (pattern[pre] == pattern[suff])
        {
            lps[suff] = pre + 1;
            pre++, suff++;
        }
        else
        {
            if (pre == 0)
            {
                lps[suff] = 0;
                suff++;
            }
            else
            {
                pre = lps[pre - 1];
            }
        }
    }
    return lps;
}
int KMP_algo(string text,string pattern){
    vector<int> lps = lps_table(pattern);
    int n = text.size();
    int m = pattern.size();
    int i = 0,j =0;
    while(i<n && j<m){
        if(pattern[j]==text[i]){
            i++,j++;
        }
        else{
            if(j==0)
            i++;
            else
            j = lps[j-1];
        }
    }
    if(j == m){
        cout<<"pattern found in text\n";
        return i-j;
    }
    return -1;
}
int main()
{
    string text = "ababcabcabababd";
    string pattern = "ababd";
    cout<<KMP_algo(text,pattern);
}
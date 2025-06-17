#include <iostream>
#include <vector>
using namespace std;
int ftd(int n,int k,int l,vector<int>& dp){
    if(n==0)
    return 0;
    if(dp[n]!=-1)
    return dp[n];
    int ans = 0;
    if(n >=1 && ftd(n-1,k,l,dp)==0)
    ans = 1; //can make opponent lose by taking 1 coin
    else if(n>=k && ftd(n-k,k,l,dp)==0)
    ans = 1;//can make opponent lose by taking k coin
    else if(n>=l && ftd(n-l,k,l,dp)==0)
    ans = 1;//can make opponent lose by taking l coin
return dp[n] = ans;
}
int fbu(int n, int k, int l)
{
    vector<int> dp(n + 1, 0); // 0 = losing, 1 = winning

    dp[0] = 0; //  no coins left = losing position
    for (int i = 1; i <= n; i++)

    {
        // Check if any move from (1), (k), or (l) leads to a losing state means winning state for the current player
        if (i >= 1 && dp[i - 1] == 0)
            dp[i] = 1;
        else if (i >= k && dp[i - k] == 0)
            dp[i] = 1;
        else if (i  >= l && dp[i - l] == 0)
            dp[i] = 1;
        // Otherwise, remains 0 (losing)
    }

    return dp[n];
}

int main()
{
    int k, l, m;
    cin >> k >> l >> m;
    vector<int> coins(m);
    for (int i = 0; i < m; i++)
    {
        cin >> coins[i];
    }

    string str;
    for (int i = 0; i < m; i++)
    {
        vector<int> dp(coins[i]+1,-1);
        int result = ftd(coins[i], k, l,dp);
        str += (result == 1 ? 'A' : 'B');  // as A(ASEON) STARTS THE GAME THEN B(BAYON) COMES in every game
    }

    cout << str << endl;
    return 0;
}


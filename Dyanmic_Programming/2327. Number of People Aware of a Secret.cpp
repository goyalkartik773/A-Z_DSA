#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
vector<int> dp;
// solve function will tell ki kisi specific day per kitne logo ko secret
// pata hai
int solve(int day, int delay, int forget) {
  if (day == 1)
    return 1;
  if (dp[day] != -1)
    return dp[day];
  int ans = 0;
  for (int days = day - forget + 1; days <= day - delay; days++) {
    if (days > 0) {
      ans = (ans + solve(days, delay, forget)) % MOD;
    }
  }
  return dp[day] = ans;
}
int peopleAwareOfSecret(int n, int delay, int forget) {
  int minDay = n - forget + 1;
  int result = 0;
  dp.resize(n + 1, -1);
  for (int i = minDay; i <= n; i++) {
    result = (result + solve(i, delay, forget)) % MOD;
  }
  return result;
}

int main() {
    
}
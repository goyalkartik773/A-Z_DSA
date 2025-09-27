#include <iostream>
#include <vector>
#include <string>
using namespace std;
int t[501][501];
int f(string &word1, string &word2, int i, int j) {
  if (i == word1.size())
    return word2.size() - j;
  if (j == word2.size())
    return word1.size() - i;
  if (t[i][j] != -1)
    return t[i][j];
  if (word1[i] == word2[j]) {
    return t[i][j] = 0 + f(word1, word2, i + 1, j + 1);
  } else {
    // insert char
    int ins = 1 + f(word1, word2, i, j + 1);
    // delete char
    int del = 1 + f(word1, word2, i + 1, j);
    // replace char
    int rep = 1 + f(word1, word2, i + 1, j + 1);
    return t[i][j] = min(ins, min(del, rep));
  }
}
int minDistance(string word1, string word2) {
  // agar options hai to recursion lag jayega just believe
  memset(t, -1, sizeof(t));
  return f(word1, word2, 0, 0);
}
int main() {}
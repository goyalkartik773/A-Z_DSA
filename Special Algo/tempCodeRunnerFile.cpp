#include<iostream>
#include<vector>
using namespace std;
bool is_substring(string haystack,string needle){
// if needle is the substring of haystack then return true
int n = haystack.size();
int m = needle.size();
for(int i=0;i<n-m+1;i++){
    string word = "";
    for(int j = i;j<m+i;j++){
        word += haystack[j];
    }
    if(needle==word)
    return true;
}
return false;
}
int main(){
string str1="kartik";
string str2="tik";
if(is_substring(str1,str2))
cout<<"valid substring";
else
cout<<"Not valid substring";
}